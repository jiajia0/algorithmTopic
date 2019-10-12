/*
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 0)
            return -1;
        vector<int> sums(nums.size(), 0);
        sums[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            sums[i] = sums[i - 1] + nums[i];
            //cout << sums[i] << endl;
        }
        
        
        for(int i = 0; i < sums.size(); i++) {
            if((i == 0 ? 0 : sums[i - 1]) == sums[sums.size() - 1] - sums[i])
                return i;
        }
        return -1;
    }
};
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0, sum = 0;
        for(int n : nums)
            total += n;
        for(int i = 0 ; i < nums.size(); i++) {
            // ½øÐÐÅÐ¶Ï
            if(sum * 2 == total - nums[i])
                return i;
            sum += nums[i];
        }
        return -1;
    }
};