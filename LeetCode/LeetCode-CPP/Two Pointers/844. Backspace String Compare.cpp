#include <iostream>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int Send = S.size() - 1;
        int Tend = T.size() - 1;
        int Scount = 0; // 统计
        int Tcount = 0;
        while(Send >= 0 || Tend >= 0) {
            // 此循环跳出的时候，就是backspace 完剩下的字符
            while(Send >= 0) {
                if(S[Send] == '#') { // 统计可以backspace 的次数
                    Send--;
                    Scount++;
                } else if(Scount > 0) {  // 进行backspace
                    Send--;
                    Scount--;
                } else
                    break;
            }

            while(Tend >= 0) {
                if(T[Tend] == '#') {
                    Tend--;
                    Tcount++;
                } else if(Tcount > 0) {
                    Tend--;
                    Tcount--;
                } else
                    break;
            }

            //cout << S[Send] << " " << T[Tend] << endl;

            if((Send >= 0) != (Tend >= 0)) // 处理 bxj##tw bxj###tw 情况，防止一个字符串遍历完，另一个没有遍历完
                return false;


            if(Send >= 0 && Tend >= 0 && S[Send] != T[Tend])
                return false;

            Send--;
            Tend--;
        }
        return true;
    }
};

int main() {
    string S = "bbbextm";
    string T = "bbb#extm";
    Solution s;
    bool ans = s.backspaceCompare(S, T);
    cout << ans << endl;
    return 0;
}
