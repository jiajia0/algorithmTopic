#include <iostream>

using namespace std;

// gcd：最大公约数
// 最小公倍数为：a*b/gcd(a,b)
// 递归版辗转相除法
/*
int gcd(int a,int b) {
    return b == 0 ? a : gcd(b, a%b);
}
*/

/*
int gcd(int a,int b) {
    int c;
    while(b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
*/

// 相减法
/*
int gcd(int a,int b) {
    while(a != b) {
        if(a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}
*/

// 暴力
int gcd(int a,int b) {
    for(int i = a; i > 0; i--)
        if(a%i==0 && b%i==0)
            return i;
    return 1;
}

int main() {
    int num = gcd(15,3);
    cout << num << endl;
    return 0;
}
