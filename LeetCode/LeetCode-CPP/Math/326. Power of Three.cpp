#include <iostream>
#include <cmath>
using namespace std;
/*
class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n/3 && n%3==0) {
            n /= 3;
        }
        return n == 1;
    }
};*/

/*
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467  % n == 0;
    }
};*/

class Solution {
public:
    bool isPowerOfThree(int n) {

        if(n < 0)
            return false;

        double d1 = int (log10(n)/log10(3));
        double d2 = log10(n)/log10(3);

        // double d = log10(n)/log10(3);
        // return floor(d) == d;

        return d1 - d2 == 0;
    }
};


int main() {
    Solution s;
    bool ans = s.isPowerOfThree(27);
    cout << ans;
    return 0;
}
