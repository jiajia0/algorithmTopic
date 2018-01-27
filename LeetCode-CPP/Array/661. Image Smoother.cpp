#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int r = M.size();// 计算出行数
        int c = M[0].size();// 计算出列数

        int count = 0;// 用来统计每个数字周围的个数
        vector<vector<int>> ans(r,vector<int>(c));//用来保存结果

        for(int i=0; i < r; i++) {
            for(int j=0; j < c; j++) {
                count = 0;
                for(int r1=i-1;r1<=i+1;r1++) {//遍历前后两行
                    for(int c1=j-1;c1<=j+1;c1++) {//遍历前后两列
                        if(0<=r1 && r1 <r && 0<=c1 && c1<c) {//如果在指定范围内的话。
                            ans[i][j] += M[r1][c1];// 将其进行相加
                            count++;
                        }
                    }
                }
                //cout << ans[i][j] << "," << count << endl;
                ans[i][j] /= count;//计算出结果
            }
        }
        return ans;
    }
};


int main() {
    Solution s;

    vector<vector<int>> M = {{1,1,1},{1,0,1},{1,1,1}};

    vector<vector<int>> result = s.imageSmoother(M);

    for(int i=0;i<result.size();i++) {
        for(int j=0;j<result[0].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
