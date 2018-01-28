#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        int flag = 0;
        int k1;
        int yushu;
        int a;

        for(int i=0;i<k;i++) {
            vector<int> ans;
            if(!flag) {
                flag = n - k;
            } else {
                flag--;
            }

            ans.push_back(flag);

            k1 = k - 1;
            yushu = n-flag;
            a = 1;

            while(k1 > 1) {
                ans.push_back(a);
                yushu = yushu - a;
                a++;
                k1--;
            }

            ans.push_back(yushu);

            result.push_back(ans);
        }
    }
};


int main() {
    Solution s;

    vector<vector<int>> result = s.combinationSum3(3,9);

    /*for(int i=0;i<result.size();i++) {
        for(int j=0;j<result[0].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }*/

    return 0;
}




