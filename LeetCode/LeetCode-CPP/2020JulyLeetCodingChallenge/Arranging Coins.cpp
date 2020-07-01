class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0;
        int i = 1;
        while(n >= i) {
            n -= i;
            ans++;
            i++;
        }
        return ans;
    }
};