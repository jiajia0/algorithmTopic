#include <iostream>
#include <vector>
using namespace std;

/*class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        for(int i = 0; i < matrix.size(); i++) {
            int start = 0, end = matrix[i].size() - 1;
            while(start + 1 < end) {
                int mid = start + (end - start) / 2;
                if(matrix[i][mid] <= target){
                    start = mid;
                } else {
                    end = mid;
                }
            }
            if(matrix[i][start] == target || matrix[i][end] == target)
                return true;
        }
        return false;
    }
};*/
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int start = 0, end = matrix.size() - 1;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(matrix[mid][0] <= target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        // 若比start 行的第一个还小，或者比 end 行的最后一个还大，则说名不存在
        if(target < matrix[start][0] || target > matrix[end][ matrix[end].size() - 1 ]) {
            return false;
        }

        // n 标记此时选则的是第n行进行查找
        int n = 0;
        if(matrix[end][0] <= target)
            n = end;
        else
            n = start;

        start = 0;
        end = matrix[0].size() - 1;

        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(matrix[n][mid] <= target)
                start = mid;
            else
                end = mid;
        }

        if(matrix[n][start] == target || matrix[n][end] == target)
            return true;

        return false;
    }
};*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix.size() == 0 || matrix[0].size() == 0)
            return false;

        int low_size = matrix.size();
        int col_size = matrix[0].size();

        int lo = 0;
        int hi = low_size * col_size - 1;

        // 直接把矩阵看成一位数组，做二分查找
        while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            // mid / col_size 计算出是第几行，mid % col_size 计算出第几列
            int curr = matrix[mid / col_size][mid % col_size];
            if (curr == target) {
                return true;
            } else if (curr < target) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        if (matrix[lo / col_size][lo % col_size] == target)
            return true;
        if (matrix[hi / col_size][hi % col_size] == target)
            return true;
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    Solution s;
    bool ans = s.searchMatrix(matrix, 6);
    cout << ans ;
    return 0;
}
