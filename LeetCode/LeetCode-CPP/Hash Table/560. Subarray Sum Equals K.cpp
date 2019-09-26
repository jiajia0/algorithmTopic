/*class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        vector<int> sum(nums.size(), 0); // sum[i] 为从 [0,i]的和
        sum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            sum[i] = sum[i-1] + nums[i];
        }
        
        for(int n  : sum)
            cout << n << " ";
        
        int res = 0;
        
        for(int start = 0; start < nums.size(); start++) {
            
            for(int end = start; end < nums.size(); end++) {
                //cout << sum[end] - sum[start] + nums[start] << endl;
                if(sum[end] - sum[start] + nums[start] == k)
                    res++;
            }
        }
        return res;
    }
};
*/

/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        for(int start = 0; start < nums.size(); start++) {
            int sum = 0;
            for(int end = start; end < nums.size(); end++){
                sum += nums[end];
                if(sum == k)
                    res++;
            }
        }
        return res;
    }
};
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int sum = 0;
        unordered_map<int,int> preSum;
        preSum[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i]; // 获取当前的和
            // 该条件成立则说明：存在一个之前位置上的sum 到当前的sum 中间差值为 k
            if(preSum.count(sum-k)) {
                res += preSum[sum-k];
            }
            preSum[sum]++; // 前一个sum的和可能有多个，所以多个之前的sum到当前的sum距离为k都可以，所以需要加上之前所有可能的sum
        }
        return res;
    }
};