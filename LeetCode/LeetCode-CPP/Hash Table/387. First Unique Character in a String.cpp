#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> alphabet(26,INT_MAX-1);
        for(int i=0;i<s.size();i++) {
            if(alphabet[s[i]-'a'] == INT_MAX-1) { // 若是第一次出现
                alphabet[s[i]-'a'] = i; // 记录index
            } else {
                if(alphabet[s[i]-'a'] != INT_MAX-1) // 如果再次（第二次）出现，则将其标记为INT_MAX
                    alphabet[s[i]-'a'] = INT_MAX;
                // 如果已经出现了很多次，则不变
            }
        }
        int minindex=  *min_element(alphabet.begin(),alphabet.end());

        return minindex >= INT_MAX-1 ? -1 : minindex;
    }
};

/*class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> count;
        for(char ch : s)
            count[ch]++;
        for(int i=0;i<s.size();i++) {
            if(count[s[i]] == 1)
                return i;
        }
        return -1;
    }
};*/

int main() {
    Solution s;
    string s1 = "leetcodetlcod";
    int ans = s.firstUniqChar(s1);
    cout << ans;
    return 0;
}
