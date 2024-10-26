// leetcode #1146. 快照数组
// 二分查找

/*
注意不要超空间

data的第一维是数组下标
每个下标用一个数组保存 快照时间戳-写入值 对
* 然后用二分查找的方式找到 最后一个不大于 snap_id 的这个索引的值 
* 可以转换成 第一个大于 snap_id 的这个索引的值
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class SnapshotArray {
    int snap_id;
    vector<vector<pair<int, int>>> data;
public:
    SnapshotArray(int length) {
        data.resize(length);
        snap_id = 0;
    }
    
    void set(int index, int val) {
        data[index].emplace_back(snap_id, val);
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto x = upper_bound(data[index].begin(), data[index].end(), pair{snap_id + 1, -1});  // * 在这里用pair{snap_id, INT_MAX}也一样
        return x == data[index].begin() ? 0 : (x - 1)->second;
    }
};