#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=0;i<numRows;i++) {
            vector<int> nums(i+1,1); // 初始化为1
            if(i > 1){
                for(int j=1;j<i;j++) {
                    nums[j] = result[i-1][j-1] + result[i-1][j]; // 当前层等于前一层的相加
                }
            }
            result.push_back(nums);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> result = s.generate(1);
    for(int i=0;i<result.size();i++) {
        for(int j=0;j<result[i].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
