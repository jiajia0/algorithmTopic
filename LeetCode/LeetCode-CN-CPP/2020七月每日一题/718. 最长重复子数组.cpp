class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size() , m = B.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int ans = 0;
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < B.size(); j++) {
                dp[i+1][j+1] = A[i] == B[j] ? dp[i][j] + 1 : 0;
                ans = max(dp[i+1][j+1], ans);
            }
        }
        return ans;
    }
};