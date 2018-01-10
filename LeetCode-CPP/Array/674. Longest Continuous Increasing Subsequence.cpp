#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        int n = nums.size();

        if(n <= 1) {
            return n;
        }

        int maxNum = 1;//记录出现最大连续值
        int count = 1;//记录当前连续出现的次数

        for(int i=1; i < n; i++) {
            //cout << nums[i-1] << "," << nums[i] << endl;
            if(nums[i-1] < nums[i]) {//如果比当前的小就是递增
                count++;
            } else {
                count = 1;
            }
            maxNum = max(count,maxNum);
        }
        return maxNum;
    }
};*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxLen = 0;//最大的连续次数
        int curIndex = 0;//当前的下标

        for(int i=0;i<nums.size();i++) {
            if(i>0 && nums[i] <= nums[i-1]) {//从第二个开始，记录下递增序列开始的位置
                curIndex = i;//记录当前的下标
            }
            maxLen = max(maxLen,i-curIndex+1);//用当前的最长连续次数和当前的连续次数
        }
        return maxLen;
    }
};


int main() {
    Solution s;
    vector<int> num = {1,3,5,4,2,3,4,5};
    int res = s.findLengthOfLCIS(num);
    cout << res;
}



