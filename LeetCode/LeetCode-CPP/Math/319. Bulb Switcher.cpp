#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
// Time Limit
/*
class Solution {
public:
    int bulbSwitch(int n) {
        vector<int> status(n + 1, 1);
        status[0] = 0;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j<= n; j++) {
                if(j % i == 0)
                    status[j] = !status[j];
            }
        }
        return accumulate(status.begin(), status.end(), 0);
    }
};*/

/*
第i个灯泡按下的次数，等于第i个灯泡的因子个数：比如6 = 1 * 6 = 2 * 3 ，所以分别会在第1轮、第2轮、第3轮、第6轮会按下。
刚开始的灯泡状态为off，所以在按下奇数次后会变成on。
若一个数不为平方数的话，那么它的因子必然是成对出现的：例如6、7、5；
若一个数为平方数：则会出现两个相同因子的情况，从而导致会出现奇数个因子：比如 16 = 1*16=2*8=4*4，其中1、2、4、8、16 一共5个因子
比如：9=1*9=3*3，1，3，9共三个因子。
所以统计1-n之间有多少平方数即可，直接对n进行开方，则小于sqrt(n)的数字的平方都在n的范围之内，所以这些数都有平方数。
*/

class Solution {
public:
    int bulbSwitch(int n) {
        return (int) sqrt(n);
    }
};

int main() {
    Solution s;
    int ans = s.bulbSwitch(16);
    cout << ans << endl;
    return 0;
}
