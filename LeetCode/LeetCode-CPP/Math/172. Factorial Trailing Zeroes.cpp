#include <iostream>

using namespace std;

// 尝试暴力法，超出范围
/*
class Solution {
public:
    int trailingZeroes(int n) {
        long long num = 1;
        // 计算n!
        while(n) {
            num *= n;
            n--;
        }

        int ans = 0;
        while(num/10 && num%10 == 0) {
            num /= 10;
            ans++;
        }
        return ans;
    }
};*/

// 只有2和5相乘，才会出现0，所以看n！能够划分为多少个 2 * 5 ，只有在阶乘数n能够被5整出的情况下，才会出现5。所以n不断的/5，最终就是答案
// 比如：n=5 , 出现一次2*5；n=15，出现三次2*5，其中分别是5、10、15.
// 比如：n=25，出现5、10、15、20、25，其中25又被划分为5 * 5.
// 统计阶乘数里有多少个 5 这个因子。
// 在n个数字中，每间隔5个数字就会出现一个能够凑成2*5的情况。所以 15 一共有三次5的间隔。25 有 5次5的间隔，并且在/5之后，还有一个5的间隔。
/*
class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};*/

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n) {
            ans += (n /= 5);
        }
        return ans;
    }
};

int main()  {
    Solution s;
    int ans = s.trailingZeroes(25);
    cout << ans ;
    return 0;
}
