#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<int> hours = {1,2,4,8};
        vector<int> minutes = {1,2,4,8,16,32};
        vector<string> result;
        for(int i=0;i<num;i++) {//处理hour的可能性
            result.push_back(hours[i]);
            for(int j=0;j<num-i;j++) {//处理mintues的可能性

            }
        }
        return result;
    }
};

int main() {
    Solution s;
    s.readBinaryWatch(1);
}
