#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x == 1)
            return 1;
        long start = 0, end = x;
        while(start + 1 < end) {
            long mid = start + (end - start) / 2;
            if(mid * mid <= x) {
                start = mid;
            } else {
                end = mid;
            }
        }
        return start;
    }
};

int main() {
    Solution s;
    int ans = s.mySqrt(1);
    cout << ans;
    return 0;
}
