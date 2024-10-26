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

class Trie {
private:
    vector<Trie*> children;
    bool isEnd;
    
    // 查找前缀
    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            // 子节点不存在。说明字典树中不包含该前缀，返回空指针
            if (node->children[ch] == nullptr) {
                return nullptr;
            }
            node = node->children[ch];  // 子节点存在。沿着指针移动到子节点，继续搜索下一个字符
        }
        return node;
    }

public:
    // 初始化前缀树对象
    Trie() {
        children.resize(26);  // 每个节点包含指向子节点的指针数组 children。此处数组长度为 26，即小写英文字母的数量。
        isEnd = false;  // 布尔字段 isEnd，表示该节点是否为字符串的结尾。
    }
    
    // Trie() : children(26), isEnd(false) {}
    
    // 向前缀树中插入字符串 word 
    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            // 子节点不存在。创建一个新的子节点，记录在 children 数组的对应位置上。
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];  // 子节点存在。沿着指针移动到子节点，继续处理下一个字符。
        }
        node->isEnd = true;
    }
    
    // 字符串 word 是否在前缀树中
    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        // 若搜索到了前缀的末尾，就说明字典树中存在该前缀。
        // 此外，若前缀末尾对应节点的 isEnd 为真，则说明字典树中存在该字符串。
        return node != nullptr && node->isEnd;
    }
    
    // 之前已经插入的字符串 word 的前缀之一是否为 prefix
    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */