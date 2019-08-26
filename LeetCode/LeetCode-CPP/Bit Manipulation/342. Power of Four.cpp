#include <iostream>
#include <cmath>
using namespace std;

// 暴力
/*
class Solution {
public:
    bool isPowerOfFour(int num) {
        while(num /4 && num % 4 == 0) {
            num /= 4;
        }
        if(num == 1)
            return true;
        return false;
    }
};
*/

// 使用log计算
/*
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num < 0)
            return false;
        double x = log10(num) / log10(4);
        return floor(x) == x;
    }
};
*/

// 利用32位int范围内最大的数字做mod，并且排除mod2的情况
/*
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && 1073741824 % num == 0 && num & 0x55555555;
    }
};
*/

// 利用二进制的性质，2的幂或者4的幂的二进制只有一个1，所以减1之后与原来的数相与必然等于0
// 然后再利用0x55555555相与排除部分2的幂的情况。
// num&(num-1) == 0 ，可以判断num是否为2的幂，因为2的幂包含4的幂，然后再排除是2的幂不是4的幂的情况。
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num&(num-1)) == 0 && num & 0x55555555;
    }
};

int main() {
    Solution s;
    bool ans = s.isPowerOfFour(4);
    cout << ans;
    return 0;
}
