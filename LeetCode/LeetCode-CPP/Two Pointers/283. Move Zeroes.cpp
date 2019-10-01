/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_i = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[zero_i++]);
            }
        }
    }
};
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int n : nums) {
            if(n != 0) {
                nums[i++] = n;
            }
        }
        while(i < nums.size()) {
            nums[i++] = 0;
        }
    }
};