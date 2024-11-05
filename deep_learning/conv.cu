#include <iostream>
#include <cuda_runtime.h>

__global__ void conv2d_cuda(float* input, float* kernel, float* output, int input_height, int input_width, int kernel_height, int kernel_width, int output_height, int output_width) {
    int tx = threadIdx.x + blockIdx.x * blockDim.x;
    int ty = threadIdx.y + blockIdx.y * blockDim.y;

    if (tx < output_width && ty < output_height) {
        float sum = 0.0f;
        for (int ky = 0; ky < kernel_height; ky++) {
            for (int kx = 0; kx < kernel_width; kx++) {
                int ix = tx + kx;
                int iy = ty + ky;
                sum += input[iy * input_width + ix] * kernel[ky * kernel_width + kx];
            }
        }
        output[ty * output_width + tx] = sum;
    }
}

int main() {
    const int input_height = 5, input_width = 5;
    const int kernel_height = 3, kernel_width = 3;
    const int output_height = input_height - kernel_height + 1;
    const int output_width = input_width - kernel_width + 1;

    // Allocate memory for input, kernel, and output
    float input[input_height][input_width] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    float kernel[kernel_height][kernel_width] = {
        {1, 0, -1},
        {1, 0, -1},
        {1, 0, -1}
    };
    float output[output_height][output_width] = {0};

    float *d_input, *d_kernel, *d_output;

    // Allocate device memory
    cudaMalloc(&d_input, input_height * input_width * sizeof(float));
    cudaMalloc(&d_kernel, kernel_height * kernel_width * sizeof(float));
    cudaMalloc(&d_output, output_height * output_width * sizeof(float));

    // Copy data to device
    cudaMemcpy(d_input, input, input_height * input_width * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_kernel, kernel, kernel_height * kernel_width * sizeof(float), cudaMemcpyHostToDevice);

    // Define grid and block size
    dim3 blockDim(16, 16);
    dim3 gridDim((output_width + blockDim.x - 1) / blockDim.x, (output_height + blockDim.y - 1) / blockDim.y);

    // Launch kernel
    conv2d_cuda<<<gridDim, blockDim>>>(d_input, d_kernel, d_output, input_height, input_width, kernel_height, kernel_width, output_height, output_width);

    // Copy result back to host
    cudaMemcpy(output, d_output, output_height * output_width * sizeof(float), cudaMemcpyDeviceToHost);

    // Print output
    for (int i = 0; i < output_height; i++) {
        for (int j = 0; j < output_width; j++) {
            std::cout << output[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Free memory
    cudaFree(d_input);
    cudaFree(d_kernel);
    cudaFree(d_output);

    return 0;
}