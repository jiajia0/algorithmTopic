#include <iostream>
#include <unordered_map>

using namespace std;

/*Input:
"abccccdd"

Output:
7*/
class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        unordered_map<char, int> alphabet;
        for(char ch : s)
            alphabet[ch]++;
        int flag = 1;
        for(auto it = alphabet.begin(); it != alphabet.end(); it++) {
            /*if(flag && (it->second == 1 || it->second % 2 == 1)) { // 若存在多余的字母， 则可以加入到回文中，但只能一次
                ans++;
                flag = 0;
            }*/
            if(ans % 2== 0 && it->second %2 ==1) // 若存在多余的字母， 则可以加入到回文中，但只能一次 , ans++之后就是奇数了
                ans++;
            ans += (it->second/2)*2; // 统计成对的字符个数
        }
        return ans;
    }
};

int main() {
    Solution s;
    string s1 = "abccccdd";
    int ans = s.longestPalindrome(s1);
    cout << ans;
    return 0;
}
