#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/*class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {

        if(nums.size() == 0 || nums.size() * nums[0].size() != r*c) {//如果等于0或者不能转换为指定的要求则返回原数组
            return nums;
        }

        queue<int> all_nums;
        vector<vector<int>> new_nums;
        int i,j;
        new_nums.resize(r);//设定为r行
        for(i=0;i<r;i++) {
            new_nums[i].resize(c);//设定每列多少个元素
        }
        for(i=0;i<nums.size();i++) {//将所有的数字放到一个数组中
            for(j=0;j<nums[i].size();j++) {
                //cout << nums[i][j] << endl;
                all_nums.push(nums[i][j]);
            }
        }

        for(i=0;i<r;i++) {//新的行数
            for(j=0;j<c;j++) {//新的列数
                new_nums[i][j] = all_nums.front();
                all_nums.pop();
            }
        }

        return new_nums;
    }
};*/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {

        if(nums.size() == 0 || nums.size() * nums[0].size() != r*c) {//如果等于0或者不能转换为指定的要求则返回原数组
            return nums;
        }

        vector<vector<int>> new_nums(r,vector<int>(c));
        int i,j;
        int row=0,col=0;

        for(i=0;i<nums.size();i++) {//处理行
            for(j=0;j<nums[0].size();j++) {//处理列
                new_nums[row][col] = nums[i][j];//取出一个元素赋值给新的数组
                col++;//列加一，向后移动一个
                if(col == c) {//如果此刻的列数已经增加到了规定的列数，就让行数加一，列数清零
                    col = 0;
                    row++;
                }
            }
        }

        return new_nums;
    }
};

int main() {
    Solution s;
    vector<vector<int>> nums;
    vector<int> num1;
    vector<int> num2;
    num1.push_back(1);
    num1.push_back(4);
    num2.push_back(2);
    num2.push_back(3);
    nums.push_back(num1);
    nums.push_back(num2);
    vector<vector<int>> n = s.matrixReshape(nums,1,4);
    int i,j;
    for(i=0;i<n.size();i++) {//将所有的数字放到一个数组中
        for(j=0;j<n[i].size();j++) {
            cout << n[i][j] << " " ;
        }
        cout << endl;
    }
    return 0;
}
