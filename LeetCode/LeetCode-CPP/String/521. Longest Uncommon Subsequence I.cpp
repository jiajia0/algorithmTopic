#include <iostream>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a == b)
            return -1;
        return a.size() >= b.size() ? a.size() : b.size();
    }
};

int main() {
    Solution s;
    string a = "aba";
    string b = "cdc";
    s.findLUSlength(a, b);
    return 0;
}
