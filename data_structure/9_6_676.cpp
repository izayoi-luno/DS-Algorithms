// leetcode #676. 实现一个魔法字典
// 字典树

/*
最原始版的字典树的搜索只能搜索某个词或者前缀是否在字典内 这样只用每次向下递归一次
但更多时候利用字典树需要遍历每一层 此时需要借助dfs辅助搜索

本题需要匹配完全每个字符 然后确定和字典内单词的不同字符数
就需要将横向的字符串比对转换成纵向的递归比对
*/

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

class MagicDictionary {
private:
    vector<MagicDictionary*> children;
    bool isEnd;

    MagicDictionary* searchPrefix(string prefix) {
        MagicDictionary* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) return nullptr;
            node = node->children[ch];
        }
        return node;
    }

public:
    MagicDictionary() {
        children.resize(26);
        isEnd = false;
    }
    
    void buildDict(vector<string> dictionary) {
        for (string word : dictionary) {
            MagicDictionary* node = this;
            for (char ch : word) {
                ch -= 'a';
                if (node->children[ch] == nullptr) node->children[ch] = new MagicDictionary();
                node = node->children[ch];
            }
            node->isEnd = true;
        }
    }
    
    bool search(string searchWord) {
        MagicDictionary* node = this;
        return dfs(node, 0, false, searchWord);
    }

    bool dfs(MagicDictionary* node, int pos, bool modified, string& searchWord) {
        if (pos == searchWord.size()) {
            return modified && node->isEnd;
        }
        int ch = searchWord[pos] - 'a';
        // 比对上就继续向下比对 比对不上就看改没改 如果没改就有一次“复活”的机会 如果之前改了一次说明“复活卡”用完了 即超过了一个字符不同 直接返回false
        if (node->children[ch]) {
            if (dfs(node->children[ch], pos + 1, modified, searchWord)) return true;
        }
        // 只能修改一次
        if (!modified) {
            for (int i = 0; i < 26; i++) {
                if (i != ch && node->children[i]) {
                    if (dfs(node->children[i], pos + 1, true, searchWord)) return true;
                }
            }
        }
        return false;
    }
};