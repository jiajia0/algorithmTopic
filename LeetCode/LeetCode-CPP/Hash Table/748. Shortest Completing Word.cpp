#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int minLengthIndex = 0;
        vector<char> license;// 用来存放licensePlate中共有多少个字母
        unordered_map<char,int> word;// 用来存放单词拆解之后的字母
        int minLength = INT_MAX;// 用力记录最小的单词位置
        int curLength = 0;// 用来记录当前单词的长度
        int isExist = true;

        for(char ch : licensePlate) {
            ch = tolower(ch);// 将其变为小写
            if(ch >= 'a' && ch <= 'z') {// 属于字母范围内
                license.push_back(ch);
            }
        }

        for(int i=0;i<words.size();i++) {
            curLength = 0;
            isExist = true;
            word.clear();// 清空
            for(char ch : words[i]) {// 将单词拆解开来存入hash表中
                curLength++;
                ch = tolower(ch);
                word[ch]++;
            }
            for(char ch : license) {// 遍历licensePlate的所有字母
                if(word[ch]-- == 0) {// 说明这个字母在单词中没有出现过
                    isExist = false;// 不存在
                    break;// 结束循环
                }
            }

            if(isExist) {// 如果存在则比较长度
                if(curLength < minLength) {
                    minLength = curLength;
                    minLengthIndex = i;
                }
            }
        }
        return words[minLengthIndex];
    }
};

int main() {
    Solution s;
    string licensePlate = "1s3 PSt";
    vector<string> words = {"step","steps","stripe","stepple"};
    string result = s.shortestCompletingWord(licensePlate,words);
    cout << result;
    return 0;
}
