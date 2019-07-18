#include <iostream>
#include <vector>
using namespace std;

// 当A与x(-K<= x <= K) 逐个相加之后生成的B，
// 要求max(B) - min(B) 的最小值，则最小化max(B),最大化min(B)
// 最小max(B：max(A)-K，最大min(B)：min(A)+K
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int minn = A[0], maxn = A[0];
        for(int n : A) {
            minn = min(n, minn);
            maxn = max(n, maxn);
        }
        return max(0, maxn - minn - 2 * K);
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 6};
    int K = 3;
    s.smallestRangeI(nums, K);
    return 0;
}
