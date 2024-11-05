import torch
import torch.nn as nn
import torch.nn.functional as F
import math

# 位置编码（Positional Encoding）类
class PositionalEncoding(nn.Module):
    def __init__(self, d_model, max_len=512):
        super(PositionalEncoding, self).__init__()
        # 生成一个最大长度为 max_len 的位置编码矩阵
        pe = torch.zeros(max_len, d_model)
        position = torch.arange(0, max_len).float().unsqueeze(1)  # 形状: (max_len, 1)
        div_term = torch.exp(torch.arange(0, d_model, 2).float() * -(math.log(10000.0) / d_model))  # 对应于d_model中每隔2个位置对应一个sin或cos
        pe[:, 0::2] = torch.sin(position * div_term)  # 偶数列使用sin
        pe[:, 1::2] = torch.cos(position * div_term)  # 奇数列使用cos
        pe = pe.unsqueeze(0)  # 增加批次维度
        self.register_buffer('pe', pe)

    def forward(self, x):
        # x的形状是 (B, n, d_model)
        return x + self.pe[:, :x.size(1)]

# 自注意力层（Multi-Head Attention）
class MultiHeadAttention(nn.Module):
    def __init__(self, d_model, num_heads):
        super(MultiHeadAttention, self).__init__()
        self.d_model = d_model
        self.num_heads = num_heads
        self.d_k = d_model // num_heads
        self.W_Q = nn.Linear(d_model, d_model)
        self.W_K = nn.Linear(d_model, d_model)
        self.W_V = nn.Linear(d_model, d_model)
        self.W_O = nn.Linear(d_model, d_model)

    def forward(self, Q, K, V):
        B, n, d = Q.shape
        Q = self.W_Q(Q).view(B, n, self.num_heads, self.d_k).transpose(1, 2)
        K = self.W_K(K).view(B, n, self.num_heads, self.d_k).transpose(1, 2)
        V = self.W_V(V).view(B, n, self.num_heads, self.d_k).transpose(1, 2)

        scores = torch.matmul(Q, K.transpose(-2, -1)) / math.sqrt(self.d_k)
        attention_weights = F.softmax(scores, dim=-1)
        output = torch.matmul(attention_weights, V).transpose(1, 2).contiguous().view(B, n, self.d_model)
        output = self.W_O(output)
        return output

# 前馈神经网络（Feed Forward Network）
class PositionwiseFeedForward(nn.Module):
    def __init__(self, d_model, d_ff=2048):
        super(PositionwiseFeedForward, self).__init__()
        self.linear1 = nn.Linear(d_model, d_ff)
        self.linear2 = nn.Linear(d_ff, d_model)

    def forward(self, x):
        return self.linear2(F.relu(self.linear1(x)))

# 编码器（Encoder）层
class EncoderLayer(nn.Module):
    def __init__(self, d_model, num_heads, d_ff):
        super(EncoderLayer, self).__init__()
        self.attention = MultiHeadAttention(d_model, num_heads)
        self.ffn = PositionwiseFeedForward(d_model, d_ff)
        self.layer_norm1 = nn.LayerNorm(d_model)
        self.layer_norm2 = nn.LayerNorm(d_model)

    def forward(self, x):
        # 自注意力层
        attn_output = self.attention(x, x, x)
        x = self.layer_norm1(x + attn_output)  # 残差连接 + 层归一化
        # 前馈神经网络
        ffn_output = self.ffn(x)
        x = self.layer_norm2(x + ffn_output)  # 残差连接 + 层归一化
        return x

# 解码器（Decoder）层
class DecoderLayer(nn.Module):
    def __init__(self, d_model, num_heads, d_ff):
        super(DecoderLayer, self).__init__()
        self.attention1 = MultiHeadAttention(d_model, num_heads)
        self.attention2 = MultiHeadAttention(d_model, num_heads)
        self.ffn = PositionwiseFeedForward(d_model, d_ff)
        self.layer_norm1 = nn.LayerNorm(d_model)
        self.layer_norm2 = nn.LayerNorm(d_model)
        self.layer_norm3 = nn.LayerNorm(d_model)

    def forward(self, x, enc_output):
        # 自注意力层
        attn_output1 = self.attention1(x, x, x)
        x = self.layer_norm1(x + attn_output1)  # 残差连接 + 层归一化
        # 编码器-解码器注意力层
        attn_output2 = self.attention2(x, enc_output, enc_output)
        x = self.layer_norm2(x + attn_output2)  # 残差连接 + 层归一化
        # 前馈神经网络
        ffn_output = self.ffn(x)
        x = self.layer_norm3(x + ffn_output)  # 残差连接 + 层归一化
        return x

# Transformer 模型
class Transformer(nn.Module):
    def __init__(self, num_encoder_layers, num_decoder_layers, d_model, num_heads, d_ff, max_len=512):
        super(Transformer, self).__init__()
        self.d_model = d_model
        self.num_encoder_layers = num_encoder_layers
        self.num_decoder_layers = num_decoder_layers
        self.positional_encoding = PositionalEncoding(d_model, max_len)
        self.encoder_layers = nn.ModuleList([EncoderLayer(d_model, num_heads, d_ff) for _ in range(num_encoder_layers)])
        self.decoder_layers = nn.ModuleList([DecoderLayer(d_model, num_heads, d_ff) for _ in range(num_decoder_layers)])
        self.fc_out = nn.Linear(d_model, d_model)

    def forward(self, src, trg):
        # 加上位置编码
        src = self.positional_encoding(src)
        trg = self.positional_encoding(trg)

        # 编码器
        for layer in self.encoder_layers:
            src = layer(src)
        
        # 解码器
        for layer in self.decoder_layers:
            trg = layer(trg, src)

        # 输出
        output = self.fc_out(trg)
        return output

def use_trans():
    # 示例使用
    B, n, d_model = 8, 10, 512  # 批次大小B，序列长度n，每个位置的特征维度d_model
    num_encoder_layers = 6
    num_decoder_layers = 6
    num_heads = 8
    d_ff = 2048

    # 随机生成输入张量 (src, trg)
    src = torch.randn(B, n, d_model)  # 输入序列
    trg = torch.randn(B, n, d_model)  # 输出序列

    # 创建 Transformer 模型
    model = Transformer(num_encoder_layers, num_decoder_layers, d_model, num_heads, d_ff)

    # 前向计算
    output = model(src, trg)
    print(output.shape)  # 输出形状： (B, n, d_model)