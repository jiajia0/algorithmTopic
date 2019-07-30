#include <iostream>
#include <string>
using namespace std;

/*
Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
*/
class Solution {
public:
    string defangIPaddr(string address) {
        string result = "";
        for(char ch : address) {
            if(ch != '.') {
                result += ch;
            } else {
                result += "[.]";
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    string address = "255.100.50.0";
    string result = s.defangIPaddr(address);
    cout << result << endl;
    return 0;
}
