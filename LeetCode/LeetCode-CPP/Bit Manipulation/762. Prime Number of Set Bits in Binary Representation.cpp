#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        vector<int> primes(21,0); // 存放20以内的质数

        primes[2] = 1;
        primes[3] = 1;
        primes[5] = 1;
        primes[7] = 1;
        primes[11] = 1;
        primes[13] = 1;
        primes[17] = 1;
        primes[19] = 1;

        while(L <= R) {
            int num = L;
            int i = 0;
            while(num) { // 统计bit中的1的个数
                if(num&1)
                    i++;
                num = num >> 1;
            }
            if(primes[i] == 1) // 判断是否为质数
                ans++;
            L++;
        }
        return ans;
    }
};
*/

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        while(L <= R) {
            int d = __builtin_popcount(L);
            ans += d < 4 ? d > 1:(d%2 && d%3);
            L++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    int ans = s.countPrimeSetBits(842,888);
    cout << ans;
    return 0;
}
