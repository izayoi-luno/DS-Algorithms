#include <iostream>
#include <vector>

void conv2d_cpu(const std::vector<std::vector<float>>& input, const std::vector<std::vector<float>>& kernel, std::vector<std::vector<float>>& output) {
    int input_height = input.size();
    int input_width = input[0].size();
    int kernel_height = kernel.size();
    int kernel_width = kernel[0].size();
    int output_height = input_height - kernel_height + 1;
    int output_width = input_width - kernel_width + 1;

    for (int i = 0; i < output_height; i++) {
        for (int j = 0; j < output_width; j++) {
            float sum = 0.0;
            for (int ki = 0; ki < kernel_height; ki++) {
                for (int kj = 0; kj < kernel_width; kj++) {
                    sum += input[i + ki][j + kj] * kernel[ki][kj];
                }
            }
            output[i][j] = sum;
        }
    }
}

int main() {
    // Example input and kernel
    std::vector<std::vector<float>> input = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<float>> kernel = {{1, 0}, {0, -1}};
    std::vector<std::vector<float>> output(2, std::vector<float>(2, 0));

    conv2d_cpu(input, kernel, output);

    // Print output
    for (const auto& row : output) {
        for (float val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}