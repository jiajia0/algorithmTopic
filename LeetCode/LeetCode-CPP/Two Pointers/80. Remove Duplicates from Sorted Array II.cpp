/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int n = 0, count = 1;
        for(int i = 1; i < nums.size(); i++) {
            // 若是相同的次数出现没有超过两次，则n向后移动
            if(nums[n] == nums[i] && count < 2) {
                n++;
                nums[n] = nums[i]; 
                count++;
            } else {
                // 此时需要交换，前面相同的出现了两次或者一次
                if(nums[n] != nums[i]) {
                    n++;
                    nums[n] = nums[i];
                    count = 1;
                }
            }
        }
        return n + 1;
    }
};
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int n : nums) {
            // 前两个必然符合条件，后面的如果
            if(i < 2 || n > nums[i - 2]) {
                nums[i++] = n;
            }
        }
        return i;
    }
};