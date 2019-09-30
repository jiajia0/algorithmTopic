class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int j = 0, i = 0;
        for(i = 0; i < s.length(); i++) {
            maxCost -= abs(s[i] - t[i]);
            if(maxCost < 0) {
                maxCost += abs(s[j] - t[j]);
                j++;
            }
        }
        return i - j;
    }
};