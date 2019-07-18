#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ans(S.size()+1, 0);
        int maxnum = S.size();
        int minnum = 0;
        for(int i = 0; i < S.size(); i++) {
            if(S[i] == 'I') {
                //cout << "I" << " " << minnum << endl;
                ans[i] = minnum;
                minnum++;
            }
            if(S[i] == 'D') {
                //cout << "D" << " " << maxnum << endl;
                ans[i] = maxnum;
                maxnum--;
            }
        }
        ans[S.size()] = minnum;
        return ans;
    }
};

int main() {
    Solution s;
    string s1 = "DDI";
    vector<int> ans = s.diStringMatch(s1);
    for(int i : ans)
        cout << i << endl;
    return 0;
}
