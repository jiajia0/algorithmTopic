#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // 用来转换为小写
        class uTol{
          public:
            char easytolow(char in){
              if(in <= 'Z' && in >= 'A'){
                  return in - ('Z' - 'z');
              }
              return in;
            }
        };
        // 用一个map来标记行数
        unordered_map<char, int> style;

        for(auto letter:"qwertyuiop"){
            style[letter] = 1;
        }
        for(auto letter:"asdfghjkl"){
            style[letter] = 2;
        }
        for(auto letter:"zxcvbnm"){
            style[letter] = 3;
        }

        uTol ul;
        vector<string> result;

        for(auto word: words){
            // 检查第一个元素是什么类型的
            int category = style[ul.easytolow(word[0])];
            bool isAllsame = true;
            // 检查该单词的所有字母
            for(auto letter:word){
                // 如果和第一个单词不一个类型
                if(style[ul.easytolow(letter)] != category){
                    isAllsame = false;
                    break;
                }
            }
            if(isAllsame){
                result.push_back(word);
            }
        }
        return result;
    }
};

/*class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        vector<string> rows = {"qwertyuiop","asdfghjkl","zxcvbnm"};
        for(string word : words) {
            bool row1 = true;// 用来标记在不在这一行中
            bool row2 = true;
            bool row3 = true;
            for(char ch : word) {
                if(row1) {
                    if(rows[0].find(tolower(ch)) == -1)
                        row1 = false;
                }
                if(row2) {
                    if(rows[1].find(tolower(ch)) == -1)
                        row2 = false;
                }
                if(row3) {
                    if(rows[2].find(tolower(ch)) == -1)
                        row3 = false;
                }
            }

            if(row1 || row2 || row3) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};*/

int main() {
    Solution s;
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
    vector<string> result = s.findWords(words);
    for(string word : result) {
        cout << word << endl;
    }
    return 0;
}
