#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word = "";

        for(char ch : s) {
            if(ch != ' ') {
                word = ch + word;
            } else {
                ans += word + " ";
                word = "";
            }
        }
        return ans +  word;
    }
};

int main() {
    Solution s;
    string s1 = "Let's take LeetCode contest";
    string ans = s.reverseWords(s1);
    cout << ans;
    return 0;
}
