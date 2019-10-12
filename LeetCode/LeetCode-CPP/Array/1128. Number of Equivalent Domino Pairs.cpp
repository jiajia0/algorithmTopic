class Solution {
public:
    // 主要思考如何存储hashmap
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> seen;
        int ans = 0;
        for(vector pair : dominoes) {
            int k = min(pair[0], pair[1]) * 10 + max(pair[0], pair[1]);
            if(seen.count(k)) {
                // 若key已经存在
                ans += seen[k];
            }
            seen[k]++;
        }
        return ans;
    }
};