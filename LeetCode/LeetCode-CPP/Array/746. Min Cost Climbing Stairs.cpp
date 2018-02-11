#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int f1=0, f2=0;
        for(int i=cost.size()-1; i >= 0; i--) {
            int f0 = cost[i] + min(f1,f2);
            f2 = f1;
            f1 = f0;
            cout << "f0:" << f0 << ",f1:" << f1 << ",f2:" << f2 << endl;
        }
        return min(f1,f2);
    }
};

int main() {
    Solution s;
    vector<int> nums;

    nums.push_back(10);
    nums.push_back(15);
    nums.push_back(20);

    int result = s.minCostClimbingStairs(nums);
    cout << result;
    return 0;
}



