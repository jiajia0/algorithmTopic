#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int n = matrix.size() >= matrix[0].size() ? matrix[0].size() : matrix.size(); // 判断出行和列哪一个更短
        for(int i = 0; i < n; i++) {
            // 从对角线向右查找
            int start = i, end = matrix[0].size() - 1;
            while(start + 1 < end) {
                int mid = start + (end - start) / 2;
                //cout << matrix[i][mid] << " ";
                if(matrix[i][mid] <= target) {
                    start = mid;
                } else {
                    end = mid;
                }
            }
            //cout << endl;
            if(matrix[i][start] == target)
                return true;
            if(matrix[i][end] == target)
                return true;
            // 从对角线向下查找
            start = i, end = matrix.size() - 1;
            while(start + 1 < end) {

                int mid = start + (end - start) / 2;
                if(matrix[mid][i] <= target) {
                    start = mid;
                } else {
                    end = mid;
                }
            }
            if(matrix[start][i] == target)
                return true;
            if(matrix[end][i] == target)
                return true;
        }
        return false;
    }
};
*/

// 若从左上和右下角考虑，则比这两个点大或者小的可能在行上也可能在列上
// 若从反对角线上的点考虑，则比点小的只能在行或者列上
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int row = matrix.size() - 1;
        int col = matrix[0].size() - 1;
        // 从左下角开始遍历，比左下角小的点只能在上一行，比它大的点只能在右边
        int j = 0;
        while(row >= 0 && j <= col) {
            if(matrix[row][j] == target) {
                return true;
            } else if(matrix[row][j] > target) { // 在上一行
                row--;
            } else { // 在右边
                j++;
            }
        }
        return false;
    }
};

int main() {

    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    Solution s;
    bool ans = s.searchMatrix(matrix, 23);
    cout << ans << endl;
    return 0;
}
