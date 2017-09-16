#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = sqrt(c);
        int b = 0;

        while (a >= b) {
            if (a*a + b*b == c) {
                return true;
            } else {
                if (a*a + b*b < c) {
                    b++;
                } else {
                    a--;
                }
            }

        }
        return false;

    }
};

int main() {
    Solution s;
    s.judgeSquareSum(3);
}



