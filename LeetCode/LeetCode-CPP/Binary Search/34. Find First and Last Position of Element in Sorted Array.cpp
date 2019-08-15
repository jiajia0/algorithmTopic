#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if(nums.size() == 0 || nums.empty())
            return ans;
        int start = 0, end = nums.size() - 1;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] <= target) { // 找到最后一个target
                start = mid;
            } else {
                end = mid;
            }
        }
        //cout << start << end << endl;
        // 由于本次查找的是出现的最后一个位置，所以最后如果end等于的话，就标记为end
        if(nums[start] == target)
            ans[1] = start;
        if(nums[end] == target)
            ans[1] = end;

        if(ans[1] == -1)
            return ans;

        start = 0, end = ans[1];
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] >= target) { // 找到最先出现的target
                end = mid;
            } else {
                start = mid;
            }
        }
        //cout << start << end << endl;
        // 如果start相等，则返回start的
        if(nums[end] == target)
            ans[0] = end;
        if(nums[start] == target)
            ans[0] = start;

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> ans = s.searchRange(nums, 6);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
