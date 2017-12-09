#include <iostream>
#include <vector>
#include <unordered_set>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int num = 0;
        while(num < bits.size() - 1) {
            if(bits[num] == 1) {//如果遇到两个字符的就加2
                num = num + 2;
            } else {//否则加一
                num++;
            }
        }
        if(num == bits.size() - 1) {//如果此时正好等于最后一个下标的位置，说明最后一个就是0
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);


    bool b = s.isOneBitCharacter(nums);
    cout << b;
    return 0;
}
