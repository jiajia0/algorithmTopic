#include <iostream>
using namespace std;

// 每次对最低位进行判断，若最低位为1，则说明互补的为0，不做操作
// 若最低位的为0，则说明互补的为1，需要根据二进制的位置加上对应的数值
class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int n = 1;
        while(num) {
            if((num & 1) == 0) { // 最低位为0
                //cout << "&" << num << endl;
                ans += n;
            }
            num = num >> 1;
            n = n << 1;
            //cout << num << " " << n << endl;
        }
        return ans;
    }
};

int main() {
    Solution s;
    int ans = s.findComplement(3);
    cout << ans;
    return 0;
}
