#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        vector<int> sorted = heights; // 排序
        sort(sorted.begin(),sorted.end());
        for(int i=0;i<sorted.size();i++) {
            if(sorted[i] != heights[i]) // 对应位置不相等，则说明站错了队
                count++;
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(3);
    int result = s.heightChecker(nums);
    cout << result;
    return 0;
}
