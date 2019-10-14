class Solution {
public:
    int balancedStringSplit(string s) {
        int l_count = 0, r_count = 0;
        int ans = 0;
        for(char ch : s) {
            if(ch == 'R') {
                r_count++;
            } else {
                l_count++;
            }
            if(l_count == r_count) {
                ans++;
                l_count = r_count = 0;
            }
        }
        return ans;
    }
};