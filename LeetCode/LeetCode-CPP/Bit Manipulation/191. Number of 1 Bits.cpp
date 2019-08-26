#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n) {
            ans += (n&1);
            n = n >> 1;
        }
        return ans;
    }
};

int main() {
    Solution s;
    uint32_t n = 00000000000000000000000000001011;
    int ans = s.hammingWeight(n);
    cout << ans;
    return 0;
}
