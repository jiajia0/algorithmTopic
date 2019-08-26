#include <iostream>
using namespace std;

// 求汉明码，即两个数字的二进制格式中，有多少位不相同
// 先让x和y进行异或操作，这样可以把二进制中不相同的位数保留下来。
// 然后分别对最低位与1进行相&操作，依次判断最低位是否为1.
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        int z = x ^ y; // eg: x = 1, x = 0001;y=4,y=0100 , x^y = 0101
        while(z) {
            if(z & 1)
                ans++;
            z = z >> 1; // 向后移一位，或者 z/2也行
        }
        return ans;
    }
};

int main() {
    Solution s;
    int ans = s.hammingDistance(1, 4);
    cout << ans;
    return 0;
}
