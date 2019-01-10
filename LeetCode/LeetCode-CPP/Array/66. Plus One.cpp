#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--) { // 从后往前位数依次加一
            digits[i]++;// 当前位加一
            if(digits[i]==10) {// 如果需要进位
                digits[i]=0;// 将当前位置为0
                if(i==0) // 如果是第一位并且还需要进位，则在最前面插入一个1，例如 9，99
                    digits.insert(digits.begin(),1);
            } else {//如果不进位，则直接返回加一后的数组
                return digits;
            }
        }
        return digits;
    }
};

// 不适用大数
/*class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int end=digits.size();
        long long sum=0,n=1;
        vector<int> result;
        while(end--) { // 将其加起来得到原来的数字
            sum += digits[end]*n;
            n *= 10;
        }
        sum++;// plus one
        while(sum) {
            result.insert(result.begin(),sum%10);
            sum /= 10;
        }
        return result;
    }
};*/

int main() {
    Solution s;
    vector<int> digits = {9,8,7,6,5,4,3,2,1,0};

    vector<int> result = s.plusOne(digits);

    for(int num : result)
        cout << num << " ";

    return 0;
}
