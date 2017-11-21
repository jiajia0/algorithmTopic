#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string s = "";
        int numbers[] = {1000,900,500,400,100,90,50,40,10,9,8,7,6,5,4,3,2,1};//几种常用的数字
        string romans[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","VIII","VII","VI","V","IV","III","II","I"};//对应的罗马数字,需要注意规则
        int i = 0;
        while(num > 0) {
            if (num - numbers[i] >= 0) {
                s = s + romans[i];
                num = num - numbers[i];
                //cout << num << " " << s << endl ;
            } else {
                i++ ;
            }
        }
        return s;
    }
};


int main() {
    Solution s;
    cout << s.intToRoman(900);
}
