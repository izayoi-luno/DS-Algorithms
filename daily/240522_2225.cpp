// leetcode #2225 找出输掉零场或一场比赛的玩家
// 哈希表

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int, int> winners;
        unordered_map<int, int> losers;
        vector<vector<int>> answer(2, vector<int>());

        for(int i = 0; i < n; i++) {
            if(winners.find(matches[i][0]) == winners.end()) winners[matches[i][0]] = 1;
            // else winners[matches[i][0]]++;

            if(losers.find(matches[i][1]) == losers.end()) losers[matches[i][1]] = 1;
            else losers[matches[i][1]]++;
        }

        for(const auto& winner : winners) {
            if(losers.find(winner.first) == losers.end()) answer[0].push_back(winner.first);
        }

        for(const auto& loser : losers) {
            if(loser.second == 1) answer[1].push_back(loser.first);
        }

        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());

        return answer;
    }
};