// leetcode #721. 账户合并
// 无向图/树
// 哈希表 + 并查集

/*
两个账户需要合并，当且仅当两个账户至少有一个共同的邮箱地址，因此这道题的实质是判断所有的邮箱地址中有哪些邮箱地址必定属于同一人，可以使用并查集实现。

为了使用并查集实现账户合并，需要知道一共有多少个不同的邮箱地址，以及每个邮箱对应的名称，
因此需要使用两个哈希表分别记录每个邮箱对应的编号和每个邮箱对应的名称，遍历所有的账户并在两个哈希表中记录相应的信息。
虽然同一个邮箱地址可能在多个账户中出现，但是同一个邮箱地址在两个哈希表中都只能存储一次。

然后使用并查集进行合并操作。
由于同一个账户中的邮箱地址一定属于同一个人，因此遍历每个账户，对账户中的邮箱地址进行合并操作。
并查集存储的是每个邮箱地址对应的编号，合并操作也是针对编号进行合并。

完成并查集的合并操作之后，即可知道合并后有多少个不同的账户。
遍历所有的邮箱地址，对于每个邮箱地址，通过并查集得到该邮箱地址属于哪个合并后的账户，即可整理出每个合并后的账户包含哪些邮箱地址。

对于每个合并后的账户，需要整理出题目要求的返回账户的格式，
具体做法是：将邮箱地址排序，账户的名称可以通过在哈希表中查找任意一个邮箱对应的名称得到，将名称和排序后的邮箱地址整理成一个账户列表。
对所有合并后的账户整理出账户列表，即可得到最终答案。
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>

using namespace std;

class UnionFind {
public:
    vector<int> parent;

    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void unionSet(int index1, int index2) {
        parent[find(index2)] = find(index1);
    }

    int find(int index) {
        if (parent[index] != index) {
            parent[index] = find(parent[index]);
        }
        return parent[index];
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> emailToIndex;
        map<string, string> emailToName;
        int emailsCount = 0;
        for (auto& account : accounts) {
            string& name = account[0];
            int size = account.size();
            for (int i = 1; i < size; i++) {
                string& email = account[i];
                if (!emailToIndex.count(email)) {
                    emailToIndex[email] = emailsCount++;
                    emailToName[email] = name;
                }
            }
        }
        UnionFind uf(emailsCount);
        for (auto& account : accounts) {
            string& firstEmail = account[1];
            int firstIndex = emailToIndex[firstEmail];
            int size = account.size();
            for (int i = 2; i < size; i++) {
                string& nextEmail = account[i];
                int nextIndex = emailToIndex[nextEmail];
                uf.unionSet(firstIndex, nextIndex);
            }
        }
        map<int, vector<string>> indexToEmails;
        for (auto& [email, _] : emailToIndex) {
            int index = uf.find(emailToIndex[email]);
            vector<string>& account = indexToEmails[index];
            account.emplace_back(email);
            indexToEmails[index] = account;
        }
        vector<vector<string>> merged;
        for (auto& [_, emails] : indexToEmails) {
            sort(emails.begin(), emails.end());
            string& name = emailToName[emails[0]];
            vector<string> account;
            account.emplace_back(name);
            for (auto& email : emails) {
                account.emplace_back(email);
            }
            merged.emplace_back(account);
        }
        return merged;
    }
};
