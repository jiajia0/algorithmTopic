#include <iostream>
#include <vector>
using namespace std;

/*class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);
        for(int i=1;i<=num;i++) {
            ans[i] = __builtin_popcount(i);
        }
        return ans;
    }
};*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
        for(int i = 1; i <= num; i++) {
            if(i%2==0) { // 此时，最后一位为0，所以此时1的个数与去掉最后一位0之后的数字中的1的个数一致，比如：110 与 11 的个数一样
                ans[i] = ans[i/2];
            } else {
                ans[i] = ans[i/2] + 1; // 此时最后一位为1，等于去掉最后一位的数，然后再加一
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> ans = s.countBits(5);
    for(int i : ans)
        cout << i << " ";

    return 0;
}
