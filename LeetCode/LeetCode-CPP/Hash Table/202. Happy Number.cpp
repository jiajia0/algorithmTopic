#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> sets;
        while(n) {
            int sum = 0;
            sets.insert(n); // 把n放入集合中
            while(n) {
                int i = n % 10;
                n /= 10;
                //cout << i << endl;
                sum += i * i;
            }
            //cout << sum << endl;
            if(sum == 1)
                return true;
            if(sets.find(sum) != sets.end()) // 陷入了循环并且不等于1
                return false;
            n = sum;
        }
        return false;
    }
};

int main() {
    Solution s;
    bool ans = s.isHappy(1);
    cout << ans << endl;
    return 0;
}
