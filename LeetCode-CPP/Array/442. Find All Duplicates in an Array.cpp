#include <iostream>
#include <vector>
#include <unordered_set>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> target;
        vector<int> res;

        for(int i=0;i<nums.size();i++) {
            if(target.find(nums[i]) == target.end()) {//如果此刻该set中不存在该数字，则存放一个数字
                target.insert(nums[i]);
            } else {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};

/*class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int n: nums) {
            n = abs(n);
            if(nums[n-1] > 0) {
                nums[n-1] = -nums[n-1];
            } else {
                res.push_back(n);
            }
        }
        return res;
    }
};*/

int main() {
    Solution s;
    vector<int> nums;

    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);

    vector<int> n = s.findDuplicates(nums);
    int i;
    for(i=0;i<n.size();i++) {//将所有的数字放到一个数组中
        std::cout << n[i] << std::endl;
    }
    return 0;
}
