class Solution {
    public int findLength(int[] A, int[] B) {
        int ans = 0;
        for(int i = 0; i < A.length; i++) {
            int maxlen = 0;
            for(int j = 0, k = i; j < B.length && k < A.length; j++, k++) {
                if(B[j] == A[k]) {
                    maxlen++;
                    ans = Math.max(ans, maxlen);
                } else {
                    maxlen = 0;
                }
            }
        }
        for(int i = 0; i < B.length; i++) {
            int maxlen = 0;
            for(int j = 0, k = i; j < A.length && k < B.length; j++, k++) {
                if(A[j] == B[k]) {
                    maxlen++;
                    ans = Math.max(ans, maxlen);
                } else {
                    maxlen = 0;
                }
            }
        }
        return ans;
    }
}