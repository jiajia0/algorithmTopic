#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 判断mid数字是否符合分组要求
    bool guess(vector<int> nums, int mid, int m) {
        long sum = 0;
        for(int i = 0 ; i < nums.size(); i++) {
            sum += nums[i];
            if(sum <= mid) {
                continue;
            }
            //cout << sum << " ";
            sum = nums[i];
            if(sum > mid)
                return false;
            m--;
        }
        //cout << mid << " " << m << endl;
        return m > 0;
    }

    int splitArray(vector<int>& nums, int m) {
        //long sum = accumulate(nums.begin(), nums.end(), 0); // 计算出数组中的总和
        long sum = 0;
        for(int n : nums)
            sum += n;
        long start = 0, end = sum;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(guess(nums, mid, m)) {
                end = mid;
            } else {
                start = mid;
            }
        }
        //cout << start << " " << end << endl;
        return end;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2147483647};
    int ans = s.splitArray(nums, 2);
    cout << ans;
    return 0;
}
