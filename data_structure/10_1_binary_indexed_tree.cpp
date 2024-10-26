// 树状数组/二叉索引树/Fenwick 树
// Binary Indexed Tree

#include <iostream>
#include <vector>

using namespace std;

class BinaryIndexedTree {
    vector<int> bit;  // 树状数组
    int size;  // 大小
    
public:
    BinaryIndexedTree(int size) : size(size) {
        bit.assign(size + 1, 0);
    }
    
    // * 二进制计算
    // 消掉最后一位1，然后再用原数减去消掉最后一位1后的数
    int lowbit(int x) {
        return x - (x & (x - 1));
    }
    // 求负数的补码
    int lowbit_(int x) {
        return x & -x;
    }

    // * 缓存或更新
    // * i 数组索引号, val 需要更新的值
    void update(int i, int val) {
        while (i <= size) {
            // 缓存数据
            bit[i] += val;  
            // 区间的下一个边界
            i += lowbit(i);
        }
    }

    // * 区间求和
    // * upBound 区间的上边界,包含, lowBound 区间的下边界，包含
    int getSum(int upBound, int lowBound) {
        // 上边界之和
        int sum = 0;
        for (int i = upBound; i > 0; i -= lowbit(i)) {
            sum += bit[i];
        }
        // 下边界之和
        int sum_ = 0;
        for (int i = lowBound - 1; i > 0; i -= lowbit(i) ) {
            sum_ += bit[i];
        }
        // 区间之差
        return sum - sum_;
    }

    // *输出缓存数据
    void showBit() {
        for (int i = 1; i < this->size; i++) cout << bit[i] <<"\t";
    }
};
