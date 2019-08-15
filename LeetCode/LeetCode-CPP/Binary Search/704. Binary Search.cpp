#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        int start = 0, end = nums.size() - 1;
        while(start + 1 < end) {
            int mid = start + (end - start)/ 2;
            if(nums[mid] <= target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if(nums[start] == target)
            return start;
        if(nums[end] == target)
            return end;
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1,0,3,5,9,12};
    int ans = s.search(nums, 9);
    cout << ans;
    return 0;
}
