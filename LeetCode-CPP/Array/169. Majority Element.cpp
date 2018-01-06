#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> res;
        int maxCount = 0;//用来存储出现最多的次数
        int majorNum;//用来存放出现次数最多
        for (int num : nums) {
            res[num]++;
            if(res[num] >= maxCount) {
                maxCount = res[num];
                majorNum = num;
            }
        }
        return majorNum;
    }
};*/

/*class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorNum = nums.size() / 2;
        sort(nums.begin(),nums.end());
        return nums[majorNum];//排序完之后，次数超过n/2的元素必然在中间
    }
};*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorNum;//出现次数最多的数字
        int count = 0;//计算出现最多的次数
        for (int i=0; i < nums.size(); i++) {//遍历一遍数组
            if(count == 0) {//如果此时计数器为0，则说明刚开始或者上一个数字出现的次数被减到0了，则让当前的数字记为出现次数最多的数字
                majorNum = nums[i];
            }
            if(majorNum == nums[i]) {//如果出现次数最多的数字等于当前的数字，就让计数器加一
                count++;
            } else {//如果不等于的让计数器减一
                count--;
            }
        }
        return majorNum;
    }
};

int main() {
    Solution s;
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);

    int result = s.majorityElement(nums);
    cout << result;
    return 0;
}


