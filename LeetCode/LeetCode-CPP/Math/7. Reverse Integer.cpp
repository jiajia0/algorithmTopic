#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x) {
            ans = ans * 10 + (x % 10);
            x /= 10;
            // 若x不为0，说明x还可以除以10，此时ans与MAX除以10对比，就相当于：下一轮ans*10与MAX对比
            if(x && ans < INT32_MIN/10)
                return 0;
            if(x && ans > INT32_MAX/10)
                return 0;
        }
        return ans;
    }
};

int main() {
    Solution s;
    int ans = s.reverse(-123);
    cout << ans;
    return 0;
}
