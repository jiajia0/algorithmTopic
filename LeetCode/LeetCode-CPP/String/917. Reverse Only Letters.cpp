#include <iostream>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int start = 0;
        int end = S.size() - 1;
        while(start < end) {
            while((S[start] < 65 || (S[start] > 90 && S[start] < 97) || S[start] > 122) && start < end)
                start++;
            while((S[end] < 65 || (S[end] > 90 && S[end] < 97) || S[end] > 122) && start < end)
                end--;
            if(start < end) {
                swap(S[start], S[end]);
                start++;
                end--;
            }
            //cout << S[start] << " " << S[end] << endl;
        }
        return S;
    }
};

int main() {
    Solution s;
    string str = "7_28]";
    string ans = s.reverseOnlyLetters(str);
    cout << ans << endl;
    return 0;
}
