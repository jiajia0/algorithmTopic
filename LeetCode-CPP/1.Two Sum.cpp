#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int,int> m;
        if (!nums.empty()) {
            int i;
            for (i = 0; i < nums.size(); i++) {
                if (m.find(nums[i]) == m.end()) {//此时map中不存在此hash
                    m[target-nums[i]] = i;
                } else {
                    ret.push_back(m[nums[i]]);//另一个的下标索引
                    ret.push_back(i);//此时的下标索引
                    return ret;
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> num;
    num.push_back(2);
    num.push_back(7);
    num.push_back(11);
    num.push_back(15);
    vector<int> ret = s.twoSum(num,9);
    cout << ret[0] << " " << ret[1];
}
