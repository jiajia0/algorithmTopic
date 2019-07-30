#include <iostream>
#include <unordered_map>

using namespace std;

/*class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, int> table;
        for(char ch : moves) {
            table[ch]++;
        }
        int i = 0;
        for(auto it = table.begin(); it != table.end(); it++) {
            if(it->first == 'U' || it->first == 'D') {
                if(table['U'] != table['D'])
                    return false;
            }
            if(it->first == 'L' || it->first == 'R') {
                if(table['L'] != table['R'])
                    return false;
            }
        }
        return true;
    }
};*/

class Solution {
public:
    bool judgeCircle(string moves) {
        int x,y;
        x = y = 0;
        for(char ch : moves) {
            if(ch == 'U')
                y++;
            else if(ch == 'D')
                y--;
            else if(ch == 'R')
                x++;
            else if(ch == 'L')
                x--;
        }
        return x == 0 && y == 0;
    }
};


int main() {
    Solution s;
    string moves = "RRDD";
    bool ans = s.judgeCircle(moves);
    cout << ans << endl;
    return 0;
}
