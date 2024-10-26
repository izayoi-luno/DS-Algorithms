// leetcode #1268. 搜索推荐系统
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

struct TrieNode {
    string word;
    unordered_map<char,TrieNode *> children;
    TrieNode() {
        this->word = "";
    }   
};

void insertTrie(TrieNode* root, const string& word) {
    TrieNode * node = root;
    for (auto c : word){
        if (!node->children.count(c)) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->word = word;
}

void searchHelper(vector<string>& res, TrieNode* node) {
    if (res.size() >= 3) return;
    if (node->word != "") res.push_back(node->word);
    for (int i = 0; i < 26; i++) {
        char ch = 'a' + i;
        if (node->children.count(ch)) {
            searchHelper(res, node->children[ch]);
        }
    }
}

vector<string> searchTrie(TrieNode* root, string prefix) {
    vector<string> res;
    for (char ch : prefix) {
        if (!root->children.count(ch)) {
            return vector<string> {};
        }
        root = root->children[ch]; 
    }
    searchHelper(res, root);
    return res;
}

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root = new TrieNode();
        for (auto & product: products){
            insertTrie(root, product);
        }
        string prefix;
        vector<vector<string>> ans;
        for (char ch : searchWord) {
            prefix.push_back(ch);
            vector<string> res = searchTrie(root, prefix);
            ans.push_back(res);
        }
        return ans;
    }
};