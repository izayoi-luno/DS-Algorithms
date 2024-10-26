// leetcode #2663. 字典序最小的美丽字符串
// 贪心

/*
首先分析一下美丽字符串的第二个条件：不包含任何长度为 2 或者更长的回文字符串。
长度为 2 的回文字符串是两个相同字符构成的字符串。
长度为 3 的回文字符串中也有两个相同字符，但下标之差为 2。
而任何长度为 2 或者更长的回文字符串，都包含一个长度为 2 或者 3 的回文字符串。
因此，只要一个字符串中的任何字符，都不与它前两个字符相同，这个字符串就不包含任何长度为 2 或者更长的回文字符串。

接下来看其他要求，返回的美丽字符串需要字典序大于 s 并且字典序最小。
贪心的思路是修改 s 的末尾字符，一点点将字符变大，如果在变大的同时能够满足美丽字符串的两个条件，那么我们就找到了要求的美丽字符串。
修改后的字符不能与前两个字符相同，因此我们在将字符变大的时候只需要将字符逐步变大三次，就能判断出修改当前字符能否满足美丽字符串的条件。
如果修改末尾字符达不到美丽字符串的条件，则我们需要将被修改的字符改为倒数第二个字符，仍然按照之前的思路一点点增大，并判断是否满足美丽字符串的两个条件。
我们从末尾字符开始，往前一点点判断是否可以修改当前字符来找到目标美丽字符串。一旦我们第一次找到了合适的下标，我们就可以来修改字符来达到目标条件。

首先我们需要修改寻找到的下标的字符，将其修改为最小的满足美丽字符串条件的字符。
接下来需要修改它右边的字符。
因为之前修改的字符已经能保证返回的字符串在字典序上大于 s，我们只需要将后续的字符修改得尽可能小即可，
因为每个字符需要与前两个字符不同，因此每个字符只需要遍历 ‘a’∼‘c’ 即可。
因为 k≥ 4，所以接下来修改的字符一定都能满足美丽字符串的条件。

在代码实现上，我们先用一个循环从 n−1 开始，往前遍历来寻找第一个被修改的字符，
找到之后，再用另一个函数 generate(s,idx,offset) 来生成修改后的字符，
其中 idx 是我们找到的下标，offsett 是将这个下标的字符增大的偏移量。
最后返回修改后的字符，如果我们未能找到目标下标，则返回空字符串。
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

class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        for (int i = s.length() - 1; i >= 0; --i) {
            unordered_set<char> blockedCharacters;
            for (int j = 1; j <= 2; ++j) {
                if (i - j >= 0) {
                    blockedCharacters.insert(s[i - j]);
                }
            }
            for (int j = 1; j <= 3; ++j) {
                if (s[i] - 'a' + j + 1 <= k && blockedCharacters.find(s[i] + j) == blockedCharacters.end()) {
                    return generate(s, i, j);
                }
            }
        }
        return "";
    }

    string generate(string s, int idx, int offset) {
        s[idx] += offset;
        for (int i = idx + 1; i < s.length(); ++i) {
            unordered_set<char> blockedCharacters;
            for (int j = 1; j <= 2; ++j) {
                if (i - j >= 0) {
                    blockedCharacters.insert(s[i - j]);
                }
            }
            for (int j = 0; j < 3; ++j) {
                if (blockedCharacters.find('a' + j) == blockedCharacters.end()) {
                    s[i] = 'a' + j;
                    break;
                }
            }
        }
        return s;
    }
};
