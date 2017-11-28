#include <iostream>
#include <vector>


using namespace std;

/*class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxnum = 0;
        int sum = 0;
        for(int num : nums) {
            sum = (num + sum) * num;
            if(maxnum < sum) {
                maxnum = sum;
            }
        }
        return maxnum;
    }
};*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxnum = 0;
        int maxHere = 0;
        for(int num : nums) {
            maxHere = (num == 0) ? 0 : maxHere + 1;
            if(maxHere > maxnum) {
                maxnum = maxHere;
            }
        }
        return maxnum;
    }
};


int main() {
    Solution s;
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);

    int n = s.findMaxConsecutiveOnes(nums);
    cout << n;
    return 0;
}
