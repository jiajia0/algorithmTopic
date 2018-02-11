#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();//得到数组的总长度
        vector<int> result(n);//计算的结果

        int left = 1;//从左边开始计算
        for(int i=0; i < n; i++) {
            if(i > 0) {//从第二个开始
                left = left * nums[i-1];//乘以左边的数字得到左边的数字总和
            }
            result[i] = left;//当前的位置等于左边的数字总和
        }

        int right = 1;//从右边开始计算
        for(int i=n-1; i >= 0; i--) {
            if(i < n-1) {//从倒数第二个开始
                right = right * nums[i+1];//得到右边的总和
            }
            result[i] = result[i] * right;//当前位置再乘以右边的总和
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    vector<int> result = s.productExceptSelf(nums);
    for(auto n : result) {
        cout << n << ",";
    }
    return 0;
}

