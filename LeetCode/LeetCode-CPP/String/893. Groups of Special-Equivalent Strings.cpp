#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<string> strs;
        for(string str : A) {
            string even = ""; // 偶数位的字符串
            string odd = "";  // 奇数
            for(int i = 0; i < str.size(); i++) {
                if(i % 2 == 0)
                    even += str[i];
                else
                    odd += str[i];
            }
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            strs.insert(odd + even);
        }
        return strs.size();
    }
};

int main() {
    Solution s;
    vector<string> A = {"abcd", "cdab", "adcb", "cbad"};
    int ans = s.numSpecialEquivGroups(A);
    cout << ans;
    return 0;
}
