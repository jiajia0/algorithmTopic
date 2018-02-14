#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;// 用来保存最后的答案
        vector<int> comb;// 用来保存当前的分组
        combination(ans,comb,k,1,n);
        return ans;
    }

    // 递归调用
    void combination(vector<vector<int>>& ans,vector<int>& comb,int k,int start,int n) {
        // 如果此时comb中的元素个数已经等于想要的；或者此时目标数为0，结束递归
        if(k == 0 && n == 0) {
            ans.push_back(comb);
            return;
        }
        for(int i = start; i <= 10-k&&i<=n; i++) {
            comb.push_back(i);
            combination(ans,comb,k,i+1,n-i);
            comb.pop_back();
        }
    }

};


int main() {
    Solution s;

    vector<vector<int>> result = s.combinationSum3(3,9);

    for(int i=0;i<result.size();i++) {
        for(int j=0;j<result[0].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}




