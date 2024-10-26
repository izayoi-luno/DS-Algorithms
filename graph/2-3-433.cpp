// leetcode #433. 最小基因变化
// 无向图 - 可达性问题 - 最短的通路
// 1. bfs

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char> change = {'A', 'C', 'G', 'T'};
        int n = bank.size();


        if(n == 0) return -1;
        int impossible = 1;
        for(int i = 0; i < n; i++) {
            if(endGene == bank[i]) impossible = 0;
        } 
        if(impossible) return -1;
        if(startGene == endGene) return 0;

        queue<string> q;
        q.emplace(startGene);
        int step = 1;
        while(!q.empty()) {
            int s = q.size();
            // 这个i的大循环很重要 虽然不影响bfs过程 但是在步数增加的时候 应该是以队列中所有情况向外探索一圈作为一步
            for(int i = 0; i < s; i++) {
                string cur = q.front();
                q.pop();
                for(int pos = 0; pos < 8; pos++) {
                    for(char c : change) {
                        string neo = cur;
                        if(c == cur[pos]) continue;
                        neo[pos] = c;
                        if(neo == endGene) return step;
                        for(int k = 0; k < n; k++) {
                            if(neo == bank[k]) {                            
                                q.emplace(neo);
                                bank[k] = 'x';
                                break;
                            }
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};