#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(int i = 0; i < A.size(); i++) {
            A[i] *= A[i];// 平方
        }
        sort(A.begin(), A.end());
        return A;
    }
};
*/

// 利用非递减的特性
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int left = 0;
        int right = A.size() - 1;
        int n = A.size() - 1;
        vector<int> result(A.size(), 0);
        while(left <= right) { // 平方最大的数字在数组的两侧
            if(abs(A[left]) < abs(A[right]))
                result[n--] = A[right]*A[right--];
            else
                result[n--] = A[left]*A[left++];
        }
        return result;
    }
};


int main() {
    Solution s;
    vector<int> num;
    num.push_back(-7);
    num.push_back(-3);
    num.push_back(2);
    num.push_back(3);
    num.push_back(11);
    vector<int> ret = s.sortedSquares(num);
    for(int n : ret) {
        cout << n << " ";
    }
}
