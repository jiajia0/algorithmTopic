#include <iostream>
using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        for(int i=0; i < str.size(); i++) {
            if(str[i] >= 65 && str[i] <= 90) {
                cout << str[i] << endl;
                str[i] += 32;
            }
        }
        return str;
    }
};

int main() {
    Solution s;
    string result = s.toLowerCase("Hello");
    cout << result << endl;
    return 0;
}
