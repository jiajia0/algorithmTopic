#include <iostream>
using namespace std;

// while()的判断条件不能是n==0，否则可能会提前结束循环，而没有达到reverse的效果
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int index = 32;
        while(index--) {
            ans += (n&1); // 加上最后一位
            n >>= 1;
            if(index) // ans 刚开始有一位，所以只需要移动31次
                ans <<= 1;
        }
        return ans;
    }
};

int main() {
    Solution s;
    uint32_t n = 43261596;
    uint32_t ans = s.reverseBits(n);
    cout << ans;
    return 0;
}
