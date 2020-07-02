class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int low = matrix[0][0], high = matrix[matrix.length - 1][matrix.length - 1];
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(check(matrix, mid, k, matrix.length)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    public boolean check(int[][] matrix, int mid, int k, int n) {
        int i = n - 1;
        int j = 0;
        int num = 0;
        while(i >= 0 && j < n) {
            if(matrix[i][j] <= mid) {
                num += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return num < k;
    }

}