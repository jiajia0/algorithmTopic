#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> numsSet;

        for(int n : nums) {
            if(numsSet.count(n) == 0) {// 如果当前没有查找过，将其添加进去
                numsSet.insert(n);
            } else {// 如果有了将其删除掉
                numsSet.erase(n);
            }
        }

        return *numsSet.begin();
    }
};*/

/*class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        unordered_set<int> numsSet;

        for(int n : nums) {
            sum += n;// 相加
            if(numsSet.count(n) == 0) {// 如果set中没有这个元素，将其添加进去
                numsSet.insert(n);
            } else {
                sum -= 2*n;// 如果存在了则减去两个n
            }
        }

        return sum;
    }
};*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 0)// 防止为空，但是这题中没有出现空的情况
            return -1;
        int ans = * nums.begin();
        for(int i=1; i < nums.size(); i++) {
            ans ^= nums[i];// 进行异或
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {};
    int result = s.singleNumber(nums);
    cout << result;
    return 0;
}
