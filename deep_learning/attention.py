import torch
import torch.nn.functional as F
import math

class SelfAttention(torch.nn.Module):
    def __init__(self, d_model, num_heads):
        super(SelfAttention, self).__init__()
        self.d_model = d_model
        self.num_heads = num_heads
        self.d_k = d_model // num_heads  # 每个头的维度

        # 查询、键、值的线性变换
        self.W_Q = torch.nn.Linear(d_model, d_model)
        self.W_K = torch.nn.Linear(d_model, d_model)
        self.W_V = torch.nn.Linear(d_model, d_model)

        # 输出的线性变换
        self.W_O = torch.nn.Linear(d_model, d_model)

    def forward(self, X):
        B, n, d = X.shape  # B 是批次大小，n 是序列长度，d 是每个位置的维度

        # 1. 计算 Q, K, V
        Q = self.W_Q(X)  # 形状: (B, n, d)
        K = self.W_K(X)  # 形状: (B, n, d)
        V = self.W_V(X)  # 形状: (B, n, d)

        # 2. 分割为多头（多个头）
        Q = Q.view(B, n, self.num_heads, self.d_k).transpose(1, 2)  # 形状: (B, num_heads, n, d_k)
        K = K.view(B, n, self.num_heads, self.d_k).transpose(1, 2)  # 形状: (B, num_heads, n, d_k)
        V = V.view(B, n, self.num_heads, self.d_k).transpose(1, 2)  # 形状: (B, num_heads, n, d_k)

        # 3. 计算注意力分数 (scaled dot-product attention)
        scores = torch.matmul(Q, K.transpose(-2, -1)) / math.sqrt(self.d_k)  # 形状: (B, num_heads, n, n)

        # 4. 应用 softmax 得到注意力权重
        attention_weights = F.softmax(scores, dim=-1)  # 形状: (B, num_heads, n, n)

        # 5. 加权求和
        output = torch.matmul(attention_weights, V)  # 形状: (B, num_heads, n, d_k)

        # 6. 拼接多头输出
        output = output.transpose(1, 2).contiguous().view(B, n, self.d_model)  # 形状: (B, n, d_model)

        # 7. 输出的线性变换
        output = self.W_O(output)  # 形状: (B, n, d_model)

        return output

import torch
import torch.nn.functional as F
import math

class MultiHeadAttention(torch.nn.Module):
    def __init__(self, d_model, num_heads):
        super(MultiHeadAttention, self).__init__()
        self.d_model = d_model  # 输入/输出的特征维度
        self.num_heads = num_heads  # 注意力头的数量
        self.d_k = d_model // num_heads  # 每个头的维度

        # 查询、键、值的线性变换
        self.W_Q = torch.nn.Linear(d_model, d_model)
        self.W_K = torch.nn.Linear(d_model, d_model)
        self.W_V = torch.nn.Linear(d_model, d_model)

        # 输出的线性变换
        self.W_O = torch.nn.Linear(d_model, d_model)

    def forward(self, X):
        B, n, d = X.shape  # B 是批次大小，n 是序列长度，d 是每个位置的维度

        # 1. 计算 Q, K, V
        Q = self.W_Q(X)  # 形状: (B, n, d)
        K = self.W_K(X)  # 形状: (B, n, d)
        V = self.W_V(X)  # 形状: (B, n, d)

        # 2. 分割为多头（多个头）
        Q = Q.view(B, n, self.num_heads, self.d_k).transpose(1, 2)  # 形状: (B, num_heads, n, d_k)
        K = K.view(B, n, self.num_heads, self.d_k).transpose(1, 2)  # 形状: (B, num_heads, n, d_k)
        V = V.view(B, n, self.num_heads, self.d_k).transpose(1, 2)  # 形状: (B, num_heads, n, d_k)

        # 3. 计算注意力分数 (scaled dot-product attention)
        scores = torch.matmul(Q, K.transpose(-2, -1)) / math.sqrt(self.d_k)  # 形状: (B, num_heads, n, n)

        # 4. 应用 softmax 得到注意力权重
        attention_weights = F.softmax(scores, dim=-1)  # 形状: (B, num_heads, n, n)

        # 5. 加权求和
        output = torch.matmul(attention_weights, V)  # 形状: (B, num_heads, n, d_k)

        # 6. 拼接多头输出
        output = output.transpose(1, 2).contiguous().view(B, n, self.d_model)  # 形状: (B, n, d_model)

        # 7. 输出的线性变换
        output = self.W_O(output)  # 形状: (B, n, d_model)

        return output

def use_attn():
    # 示例使用
    B, n, d_model = 8, 10, 64  # 批次大小B，序列长度n，每个位置的特征维度d_model
    num_heads = 8  # 多头注意力的头数

    # 随机生成输入张量
    X = torch.randn(B, n, d_model)

    # 创建自注意力模型
    attention_layer = SelfAttention(d_model, num_heads)

    # 计算输出
    output = attention_layer(X)
    print(output.shape)  # 期望输出形状: (B, n, d_model)
    
def use_mh_attn():
    # 示例使用
    B, n, d_model = 8, 10, 64  # 批次大小B，序列长度n，每个位置的特征维度d_model
    num_heads = 8  # 多头注意力的头数

    # 随机生成输入张量
    X = torch.randn(B, n, d_model)

    # 创建多头注意力模型
    attention_layer = MultiHeadAttention(d_model, num_heads)

    # 计算输出
    output = attention_layer(X)
    print(output.shape)  # 期望输出形状: (B, n, d_model)

