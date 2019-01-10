#include <iostream>

using namespace std;


class Solution {
public:
    int fib(int N) {
        if(N==1)
            return N;
        int p1=0,p2=1,sum=0;
        for(int i=0;i<N;i++) {
            sum = p1+p2;
            p1 = p2;
            p2 = sum;
        }
        return sum;
    }
};


int main() {
    Solution s;
    cout << s.fib(6);
    return 0;
}
