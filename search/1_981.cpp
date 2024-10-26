// leetcode #981. 基于时间的键值存储
// 哈希表 + 二分查找

/*
用一个哈希表存储 set 操作传入的数据。
具体地，哈希表的键为字符串 key，值为一个二元组列表，二元组中存储的是时间戳 timestamp 和值 value。

由于 set 操作中的时间戳都是严格递增的，因此二元组列表中保存的时间戳也是严格递增的，
这样我们可以根据 get 操作中的 key 在哈希表中找到对应的二元组列表 pairs，然后根据 timestamp 在 pairs 中二分查找。
我们需要找到最大的不超过 timestamp 的时间戳，
对此，我们可以二分找到第一个超过 timestamp 的二元组下标 i，
若 i>0 则说明目标二元组存在，即 pairs[i−1]，否则二元组不存在，返回空字符串。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class TimeMap {
    unordered_map<string, vector<pair<int, string>>> m;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto &pairs = m[key];
        // *核心：up函数的用法：对于元素为pair、tuple、数组的待查找数组，会依次按照位数比较大小
        // 使用一个大于所有 value 的字符串，以确保在 pairs 中含有 timestamp 的情况下也返回大于 timestamp 的位置
        pair<int, string> p = {timestamp, string({127})};
        auto i = upper_bound(pairs.begin(), pairs.end(), p);
        if (i != pairs.begin()) {
            return (i - 1)->second;
        }
        return "";
    }
};
