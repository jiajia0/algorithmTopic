#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> result(A[0].size(),vector<int>(A.size()));//申请一个新的数组，大小为转置之后的
        int i,j;
        for(i=0;i<A[0].size();i++) {
            for(j=0;j<A.size();j++) {
                result[i][j] = A[j][i];
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    //vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> A = {{1,2,3},{4,5,6}};
    vector<vector<int>> ret = s.transpose(A);
    int i,j;
    for(i=0;i<ret.size();i++) {
        for(j=0;j<ret[0].size();j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
