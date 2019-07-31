#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string toGoatLatin(string S) {
        string ans = "";
        int num = 1; // 用来标记是第几个单词
        stringstream ss(S);
        string word;
        while(ss >> word) {
            // 若是元音
            if(word[0] == 'a' || word[0] == 'A' || word[0] == 'e' || word[0] == 'E' || word[0] == 'i' || word[0] == 'I' || word[0] == 'O' || word[0] == 'o' || word[0] == 'u' || word[0] == 'U')
                word += "ma";
            else {
                word += word[0];
                word.erase(0,1);// 删除第一个字符
                word += "ma";
            }
            for(int i = 1; i <= num; i++)
                word += "a";
            ans += word + " ";
            word = "";
            num++;
        }
        ans.erase(ans.size()-1,1); // 去掉多余的空格
        return ans;
    }
};

int main() {
    Solution s;
    string str = "I speak Goat Latin";
    string ans = s.toGoatLatin(str);
    cout << ans;
    return 0;
}
