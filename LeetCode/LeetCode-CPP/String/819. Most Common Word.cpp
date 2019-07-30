#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        stringstream ss(paragraph);
        string word = "";
        unordered_map<string, int> table;
        // !?',;.
        for(int i = 0; i < paragraph.size(); i++) {
            if(paragraph[i] >= 65 &&  paragraph[i] <= 122) { // 若是大写的则转为小写的
                if(paragraph[i] <= 90)
                    word += paragraph[i] + 32;
                else
                    word += paragraph[i];
            } else { // 标点符号或者空格
                if(word != "" && find(banned.begin(), banned.end(), word) == banned.end()) // 若不存在与banned中，则添加到map中
                    table[word]++;
                word = "";
            }
        }
        int i = 0;
        for(auto it = table.begin(); it != table.end(); it++) {
            if(it->second > i) {
                i = it->second;
                word = it->first;
            }
        }
        return word;
    }
};

int main() {
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    Solution s;
    vector<string> banned =  {"hit"};
    string ans = s.mostCommonWord(paragraph, banned);
    cout << ans << endl;
    return 0;
}
