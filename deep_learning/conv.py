import numpy as np

def conv2d(input_tensor, kernel, stride=1, padding=0):
    """
    对输入张量进行2D卷积操作
    :param input_tensor: 输入张量，形状 (B, C, H, W)
    :param kernel: 卷积核，形状 (C, kH, kW)
    :param stride: 步幅
    :param padding: 填充
    :return: 卷积后的输出张量，形状 (B, C, H_out, W_out)
    """
    B, C, H, W = input_tensor.shape  # 获取输入张量的形状
    kC, kH, kW = kernel.shape  # 获取卷积核的形状

    # 确保输入通道数与卷积核的输入通道数匹配
    assert C == kC, "Input channels must match kernel channels."

    # 计算输出特征图的高度和宽度
    H_out = (H + 2 * padding - kH) // stride + 1
    W_out = (W + 2 * padding - kW) // stride + 1

    # 为输入张量添加零填充
    if padding > 0:
        input_tensor = np.pad(input_tensor, ((0,), (0,), (padding,), (padding,)), mode='constant', constant_values=0)

    # 创建输出张量
    output_tensor = np.zeros((B, C, H_out, W_out))

    # 执行卷积操作
    for b in range(B):  # 遍历每个批次
        for c in range(C):  # 遍历每个通道
            for h_out in range(H_out):  # 遍历输出特征图的高度
                for w_out in range(W_out):  # 遍历输出特征图的宽度
                    # 计算卷积区域的起始和结束位置
                    h_start = h_out * stride
                    h_end = h_start + kH
                    w_start = w_out * stride
                    w_end = w_start + kW

                    # 计算卷积结果，逐元素相乘并求和
                    output_tensor[b, c, h_out, w_out] = np.sum(
                        input_tensor[b, c, h_start:h_end, w_start:w_end] * kernel[c]
                    )

    return output_tensor

def use_conv():
    # 示例使用
    B, C, H, W = 2, 3, 5, 5  # 批次大小B，通道数C，高度H，宽度W
    kH, kW = 3, 3  # 卷积核的高度和宽度
    stride = 1  # 步幅
    padding = 0  # 填充

    # 创建随机输入张量和卷积核
    input_tensor = np.random.randn(B, C, H, W)
    kernel = np.random.randn(C, kH, kW)  # 卷积核的形状为 (C, kH, kW)

    # 执行卷积
    output_tensor = conv2d(input_tensor, kernel, stride, padding)

    print("Input shape:", input_tensor.shape)  # 期望 (B, C, H, W)
    print("Kernel shape:", kernel.shape)  # 期望 (C, kH, kW)
    print("Output shape:", output_tensor.shape)  # 期望 (B, C, H_out, W_out)