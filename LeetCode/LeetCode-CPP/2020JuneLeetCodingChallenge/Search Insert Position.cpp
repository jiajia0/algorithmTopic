class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int low = 0, high = nums.size();
        while(high > low) {
            int mid = low + (high - low) / 2;
            if(nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};