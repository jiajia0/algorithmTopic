#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i,sum=0;
        for(i=0;i<nums.size();i=i+2) {
            sum += nums[i];
        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(3);
    s.arrayPairSum(nums);
    return 0;
}
