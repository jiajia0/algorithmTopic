#include <iostream>
using namespace std;

// 两位数：ab = a*10+b = a*9+a+b
// 三位数：abc = a*100+b*10+c = a*99+b+9+a+b+c
// mod 9 之后，剩余的为：a+b 或者 a+b+c
// 为了规避9的倍数mod 9 之后为0，所以采用 (num - 1)%9 + 1.
// 减一操作之后：9的倍数得到的结果应该为9，其余的结果与num mod 9 一样。
// 若是mod8，也可以使用n-1的操作。
/*
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};*/

// 上面的直观形式，单独处理9的倍数的情况
/*class Solution {
public:
    int addDigits(int num) {
        if(num > 9) {
            num = num % 9;
            if(num == 0)
                return 0;
        }
        return num;
    }
};*/

// 暴力
class Solution {
public:
    int addDigits(int num) {
        while(num > 9) {
            int sum = 0;
            while(num) { // 各位进行相加，得到新的num
                sum += (num%10);
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};

int main() {
    Solution s;
    int ans = s.addDigits(99);
    cout << ans ;
    return 0;
}
