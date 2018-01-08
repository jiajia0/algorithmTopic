#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size() + 1;//得到理论上应该的总数

        for(int i=0; i < nums.size(); i++) {//计算出来此时的总和
            sum += nums[i];
        }
        return ((n*(n-1))/2 - sum);//使用高斯公式计算出来总数减去计算出来的实际数字
    }
};*/

/*class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());//进行排序

        if(nums[0] != 0) {//如果第一个数字不等于0
            return 0;
        }

        if(nums[nums.size()-1] != nums.size()) {//如果最后一个数字不等于数组的长度
            return nums.size();
        }

        for(int i=1;i<nums.size();i++) {
            if(nums[i-1]+1 != nums[i]) {//如果前面的的加上一之后与当前的一位不相等，则说明缺失了
                return nums[i-1] + 1;
            }
        }
    }
};*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> numSet;

        for(int i=0; i<nums.size(); i++) {//遍历数组，将其内容放到哈希表中
            numSet[nums[i]]++;//对应的value加一
        }

        for(int i=0; i <= nums.size(); i++) {//从0到n遍历看看缺少哪一个数字
            if(numSet[i] == 0) {
                return i;
            }
        }
    }
};

/*class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int miss = nums.size();
        for(int i=0; i<nums.size(); i++) {//进行异或，因为0到n与数组中以及数组长度进行异或的话，相等部分会抵消，最后留下缺失值
            miss ^= i ^ nums[i];
        }
        return miss;
    }
};*/

int main() {
    Solution s;
    vector<int> num;
    num.push_back(2);
    num.push_back(0);
    num.push_back(1);
    int ret = s.missingNumber(num);
    cout << ret;
}


