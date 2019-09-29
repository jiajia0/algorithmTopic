class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m, nums;
        for(int n : arr) {
            m[n]++;
        }
        
        for(auto it = m.begin(); it != m.end(); it++) {
            if(nums[it->second] == 1)
                return false;
            nums[it->second] = 1;
        }
        return true;
    }
};