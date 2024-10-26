// leetcode #14. 最长公共前缀
// 字典树

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <numeric>
#include <set>

using namespace std;

class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix (string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) return nullptr;
            node = node->children[ch];
        }
        return node;
    }

public:
    int prefixSize = 0;

    Trie() {
        children.resize(26);
        isEnd = false;
    }

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) node->children[ch] = new Trie();
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    void dfs(string& res, Trie* root, int minSize) {
        if (prefixSize == minSize) return;
        int num = 0;
        int prf = 0;
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != nullptr) {
                num++;
                prf = i;
            }
        }
        if (num == 1) {
            res.push_back('a' + prf);
            prefixSize++;
            dfs(res, root->children[prf], minSize);
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* root = new Trie();
        int minSize = INT_MAX;
        for (auto& str : strs) {
            if (str == "") return string {};
            int m = str.size();
            minSize = min(minSize, m);
            root->insert(str);
        }
        string res;
        root->dfs(res, root, minSize);
        return res;
    }
};