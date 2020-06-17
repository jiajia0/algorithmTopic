class Solution {
    public int maxScoreSightseeingPair(int[] A) {
        int ans = 0;
        int mx = A[A.length - 1] - A.length - 1; // 记录最大的 A[j] - j
        for(int i = A.length - 2; i >= 0; i--) {
            mx = Math.max(mx, A[i + 1] - i - 1); // 计算出最大的A[j] - j
            ans = Math.max(ans, mx + A[i] + i);
        }
        return ans;
    }
}