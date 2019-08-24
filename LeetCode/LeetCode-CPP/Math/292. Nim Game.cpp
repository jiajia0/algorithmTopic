#include <iostream>
using namespace std;

// 如果面对的是4的倍数，则一定会输。
// 比如：刚开始为4，无论自己在1-3中怎么取，对方都可以一次取完。
// 比如：刚开始为8，无论自己怎么取，对方都可以让自己面对4.
// 自己取n，对手可以取4-n。
// 所以如果刚开始是4的倍数，则输。
// 巴什博弈：n%(m+1) != 0 ， 先手胜
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

int main() {
    Solution s;
    s.canWinNim(4);
    return 0;
}
