#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int,int> m;
        if (!nums.empty()) {
            int i;
            for (i = 0; i < nums.size(); i++) {
                //if (m.find(nums[i]) == m.end()) {//此时map中不存在此hash
                if(!m.count(nums[i])) {
                    m[target-nums[i]] = i;
                } else {
                    ret.push_back(m[nums[i]] + 1);//另一个的下标索引
                    ret.push_back(i + 1);//此时的下标索引
                    return ret;
                }
            }
        }
        return ret;
    }
};*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int start = 0;//从头开始查找
        int end = nums.size() - 1;//从尾部开始查找
        int sum;//记录start位置和end位置的和
        while(start < end) {//从两边开始向中间靠近
            sum = nums[start] + nums[end];
            if(sum == target) {//如果此时相等，则说明找到了正确的位置
                ret.push_back(start + 1);
                ret.push_back(end + 1);
                break;
            } else if (sum < target) {//如果两个位置之和小于目标数，则让start向后移动一位
                start++;
            } else {//否则让end向前移动一位
                end--;
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

