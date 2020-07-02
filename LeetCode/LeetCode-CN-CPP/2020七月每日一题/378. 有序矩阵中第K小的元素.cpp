class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low = matrix[0][0], high = matrix[matrix.size() - 1][matrix.size() - 1];
        while(low < high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;
            for(int i = 0; i < matrix.size(); i++) {
                cnt += (upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin());
            }
            
            if(cnt < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        //cout << low << " " << high << endl;
        return low;
    }
};