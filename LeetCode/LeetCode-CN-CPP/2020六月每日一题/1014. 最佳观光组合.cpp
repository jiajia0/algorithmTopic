class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        // 将A[i] + A[j] + i - j 分解为：A[j] - j + A[i] + i
        int ans = 0;
        int mx = A[0] + 0; // 记录最大的A[i] + i;
        for(int i = 1; i < A.size(); i++) {
            mx = max(mx, A[i - 1] + i - 1); // 记录最大的A[i] + i
            ans = max(ans, A[i] - i + mx); // 针对当前j来说，计算最大的A[i] + i + A[j] - j
        }
        return ans;
    }
};