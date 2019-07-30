#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0; i < s.size() / 2; i++) {
            swap(s[i], s[s.size() - i - 1]);
        }
    }
};

int main() {
    Solution s;
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    s.reverseString(str);
    for(char ch : str)
        cout << ch ;
    return 0;
}
