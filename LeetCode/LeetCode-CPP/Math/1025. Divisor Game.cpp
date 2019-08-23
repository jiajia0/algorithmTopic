#include <iostream>
#include <vector>
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
/*
class Solution {
public:
    bool divisorGame(int N) {
        return N %2 ==0;
    }
};*/

class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> ans(N + 1, false);// 用来保存第N个数字的情况下，Alice是否胜利
        ans[0] = true;

        for(int i = 2; i <= N; i++) {
            //cout << i << "-------------" << endl;
            // j 小于 i的开方， 因为需要观察的是i-j，若j大于i的开方，则i-j的数字在之前已经计算过了，
            // 例如：i=9,j=3, 9-1 , 9-2 , 9-3 没有计算过，但是9-4=5之前在6-1的时候已经计算过了
            for(int j = 1; j * j < i; j++) {
                //cout << i - j << endl;
                if(i % j == 0 && !ans[i - j]) // 若i%j==0则说明此时Alice可以行动，如果 ans[i-j] == false ，则说明面对i-j数字的人会输，相当于Alice把数的情况推给了Bob
                    ans[i] = true;
            }
        }
        return ans[N];
    }
};


int main() {
    Solution s;
    s.divisorGame(9);
    return 0;
}
