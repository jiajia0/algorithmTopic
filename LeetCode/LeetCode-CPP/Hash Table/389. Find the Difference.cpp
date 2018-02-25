#include <iostream>
#include <unordered_map>

using namespace std;

/*class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans;
        unordered_map<char,int> chCount;
        for(char ch : s) {
            chCount[ch]++;
        }
        for(char ch : t) {
            if(chCount[ch]-- == 0) {
                ans = ch;
                break;
            }
        }
        return ans;
    }
};*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        for(char c : s) ans ^= c;
        for(char c : t) ans ^= c;
        return ans;
    }
};

int main() {
    Solution sl;
    string s = "abcd";
    string t = "abcde";
    char result = sl.findTheDifference(s,t);
    cout << result;
    return 0;
}
