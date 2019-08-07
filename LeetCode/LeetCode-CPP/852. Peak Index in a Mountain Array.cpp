#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        for(int i = 1; i < A.size() - 1; i++) {
            if(A[i] > A[i - 1] && A[i] > A[i + 1]) // 比两边都大，则说明是peak了
                return i;
        }
        return A.size();
    }
};

int main() {
    Solution s;
    vector<int> A = {0, 1, 0};
    int ans = s.peakIndexInMountainArray(A);
    cout << ans;
    return 0;
}
