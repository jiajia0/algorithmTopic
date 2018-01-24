#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        unordered_map<int,int> ans;//用来保存元素和下一个坐标的位置
        int r = matrix.size();//多少行
        int c = matrix[0].size();//多少列
        if(r == 1 || c == 1) {
            return true;
        }
        int i=0;
        while(i < c-1) {
            ans[i+1] = matrix[0][i];
            //cout << "当前元素：" << matrix[0][i] << "，下一个预期的坐标" << i+1 << endl;
            i++;
        }
        for(i=1;i<r;i++) {
            int j=c-1;
            while(j > 0) {//比较其他的是否与预期的一样
                //cout << j << "," << ans[j] << "," << matrix[i][j] << endl;
                if(ans[j] == matrix[i][j]) {//如果一样则更新信息
                    ans[j+1] = matrix[i][j];
                } else {
                    //cout << "quit" << i << "," << j;
                    return false;
                }
                j--;
            }
            ans[1] = matrix[i][0];//将新的加入其中
        }
        return true;
    }
};*/


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size()-1;i++) {
            for(int j=0;j<matrix[0].size()-1;j++) {
                if(matrix[i][j] != matrix[i+1][j+1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1,2,3,4};
    vector<int> nums2 = {5,1,2,3};
    vector<int> nums3 = {9,5,1,2};

    vector<vector<int>> matrix;
    matrix.push_back(nums1);
    matrix.push_back(nums2);
    matrix.push_back(nums3);

    bool result = s.isToeplitzMatrix(matrix);
    cout << result;
    return 0;
}


