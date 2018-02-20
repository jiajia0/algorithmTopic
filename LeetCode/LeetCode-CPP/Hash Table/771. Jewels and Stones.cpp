#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        for(auto s : S) {
            if(J.find(s)!=-1) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    string J = "aA";
    string S = "aAAbbbb";
    int result = s.numJewelsInStones(J,S);
    cout << result;
    return 0;
}
