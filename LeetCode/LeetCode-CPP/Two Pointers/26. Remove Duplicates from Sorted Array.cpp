class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        // n和i错开一位
        int n = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[n] != nums[i]) {
                n++;
                nums[n] = nums[i];
            }
        }
        // 数组的长度要比index多一
        return n + 1;
    }
};