class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int res = 0;
        unordered_map<int,int> hash;
        for(int n : nums)
            hash[n]++;
        for(auto it = hash.begin(); it != hash.end(); it++) {
            int next = it->first + 1;
            if(hash.count(next) && hash[next] + it->second > res) {
                res = hash[next] + it->second;
            }
        }
        return res;
    }
};