#include <iostream>
using namespace std;

/*
奇数的因子（N%x==0）只能为奇数，偶数的因子可以为偶数也可以为奇数。
结束的时候，谁面对的是N=2，则会胜利，比如Alice为2，则Alice胜利，Alice为3，Alice只能选则1，则Bob为2，Bob胜利。
Alice为4，Alice选则1，则Bob为3，输。

所以，当刚开始N为偶数的时候，Alice可以选则一个奇数因子x，然后N-x为奇数，
则Bob面对的为奇数，只能选则奇数因子，奇数-奇数为偶数，则Alice面对的为偶数，如此往复，Alice面对的为2，所以Alice胜利.

当刚开始为奇数时，Alice只能选则奇数，然后奇数-奇数为偶数，则Bob面对偶数，则Bob会胜利。

所以当N为偶数时，Alice胜利。

*/
class Solution {
public:
    bool divisorGame(int N) {
        return N %2 ==0;
    }
};

int main() {

    return 0;
}
