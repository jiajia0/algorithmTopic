class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        vector<int> c(60);
        for(int t : time) {
            ans += c[t%60 == 0 ? 0 : 60 - t%60];
            //ans += c[(600 - t) % 60];
            c[t%60]++;
        }
        return ans;
    }
};