#include <iostream>

using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        bool isRotated = false;
        for(int i = 1; i <= N; i++) {
            int num = i;
            while(num) {
                if(num % 10 == 3 || num % 10 == 4 || num % 10 == 7) { // 余数在这些中的都不符合要求
                    isRotated = false;
                    break;
                }
                if(num % 10 == 2 || num % 10 == 5 || num % 10 == 6 || num % 10 == 9) { // 这些数字符合要求
                    isRotated = true;
                }
                // 0 , 1 , 10 , 8 均不符合：we get a valid number that is different from X
                num /= 10;
            }
            if(isRotated) {
                count++;
            }

            isRotated = false;
        }
        return count;
    }
};

int main() {
    Solution s;
    int ans = s.rotatedDigits(10);
    cout << ans;
    return 0;
}
