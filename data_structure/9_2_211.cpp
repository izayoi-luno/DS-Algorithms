// leetcode #211. 添加与搜索单词 - 数据结构设计
// 字典树/前缀树 Trie

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <numeric>

using namespace std;

struct TrieNode{
    vector<TrieNode *> child;
    bool isEnd;
    TrieNode() {
        this->child = vector<TrieNode *>(26,nullptr);
        this->isEnd = false;
    }
};

void insert(TrieNode * root, const string & word) {
    TrieNode * node = root;
    for (char ch : word) {
        ch -= 'a';
        if (node->child[ch] == nullptr) {
            node->child[ch] = new TrieNode();
        }
        node = node->child[ch];
    }
    node->isEnd = true;
}

class WordDictionary {
public:
    WordDictionary() {
        trie = new TrieNode();
    }
    
    void addWord(string word) {
        insert(trie,word);
    }
    
    // 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。
    // word 中可能包含一些 '.' ，每个 . 都可以表示任何一个字母。 所以借助深度优先搜索
    bool search(string word) {
        return dfs(word, 0, trie);
    }

    bool dfs(const string & word,int index,TrieNode * node) {
        if (index == word.size()) {
            return node->isEnd;    
        }
        char ch = word[index];
        if (ch >= 'a' && ch <= 'z') {
            TrieNode * child = node->child[ch - 'a'];
            if (child != nullptr && dfs(word, index + 1, child)) {
                return true;
            }
        } else if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                TrieNode * child = node->child[i];
                if (child != nullptr && dfs(word, index + 1, child)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    TrieNode * trie;
};