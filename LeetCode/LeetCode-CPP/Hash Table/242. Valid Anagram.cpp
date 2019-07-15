#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char, int> chars;
        for(int i = 0; i < s.size(); i++) {
            chars[s[i]]++; // 第一个单词拆开后放入map中
            chars[t[i]]--; // 第二个单词拆开后消耗map
        }
        for(auto it = chars.begin(); it != chars.end(); it++) {
            if(it->second != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    string s1 = "anagram";
    string s2 = "nagaram";
    bool ans = s.isAnagram(s1, s2);
    cout << ans;
    return 0;
}
