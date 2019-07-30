#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> uniqueMorse;// 保存摩斯密码，set确保唯一性

        // 定义摩斯密码
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.",
                         "....","..",".---","-.-",".-..","--","-.",
                         "---",".--.","--.-",".-.","...","-","..-",
                         "...-",".--","-..-","-.--","--.."};

        // 遍历所有的单词
        for(string word : words) {
            string morseForWord = "";// 保存单词的摩斯密码
            for(char ch : word) { //将单词转换为对应的摩斯密码
                morseForWord += morse[ch - 'a']; // 将摩斯密码记录下来
            }
            uniqueMorse.insert(morseForWord);
        }
        return uniqueMorse.size();
    }
};

int main() {
    Solution s;
    vector<string> words = {"gin", "zen", "gig", "msg"};
    int result = s.uniqueMorseRepresentations(words);
    cout << result;
}
