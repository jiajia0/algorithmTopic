/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sum = 0;
        for(int n : nums) {
            sum += n;
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        return ans;
    }
};
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int sum = dp[0];
        for(int i = 1; i < n; i++) {
            dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            sum = max(sum, dp[i]);
        }
        return sum;
    }
};