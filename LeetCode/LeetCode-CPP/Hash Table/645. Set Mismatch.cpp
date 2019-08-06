#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        vector<int> table(nums.size() + 1, 0);  //  index 0 不进行填充
        for(int i : nums)
            table[i]++;
        for(int i = 1; i < table.size(); i++) {
            if(table[i] == 0) { // 缺失
                ans.push_back(i);
            }
            if(table[i] == 2) { // 重复
                ans.insert(ans.begin(), i);
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 2};
    vector<int> ans = s.findErrorNums(nums);
    for(int i : ans)
        cout << i << " ";
    return 0;
}
