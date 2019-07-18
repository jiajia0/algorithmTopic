#include <iostream>
#include <vector>
using namespace std;

/*class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        int temp = left;
        vector<int> result;
        for(int num=left;num<=right;num++) {// 在指定范围内循环
            temp = num;
            if(!(temp%10)) { // 判断是否属于10、20、300类型
                continue;
            }
            while(temp && num%(temp%10) == 0) {// 如果当前位数满足条件就继续试探下一位
                temp /= 10;
                if(temp%10==0){ \\ 判断是否属于101、203这种的
                    break;
                }
            }
            if(temp == 0) {
                result.push_back(num);
            }
        }
        return result;
    }
};*/

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        int temp = left;
        int mod;
        vector<int> result;
        for(int num=left;num<=right;num++) {// 在指定范围内循环
            temp = num;

            while(temp) {
                mod = temp%10; // 求出此时的余数
                if(mod==0 || num%mod!=0)// 如果此时余数等于0说明是10的倍数则退出，如果此时不满足条件也退出
                    break;
                temp /= 10;
            }

            if(temp == 0) {
                result.push_back(num);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> result = s.selfDividingNumbers(1,22);
    for(int i : result) {
        cout << i << ",";
    }
    return 0;
}
