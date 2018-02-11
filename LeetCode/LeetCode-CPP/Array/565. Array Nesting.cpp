#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxLen = 1;
        int curLen = 1;

        for(int i=0; i < nums.size(); i++) {
            curLen = 1;//从1开始计算，因为最后如果下标为0的话就结束了，不会访问到最开始的位置
            int curIndexNum = nums[i];//当前下标对应的数字

            //如果当前下标对应的数字不等于0，并且不等于自身
            while(curIndexNum && curIndexNum!=i) {
                curLen++;
                curIndexNum = nums[curIndexNum];//找到下一个数字
            }
            maxLen = max(maxLen,curLen);
        }
        return maxLen;
    }
};*/


/*class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxLen = 0;
        int curLen = 0;

        //对之前的进行优化，访问过的不需要再次访问了
        for(int i=0; i < nums.size(); i++) {
            curLen = 0;//从0开始，因为最后如果下标是0的话也会访问，所以需要从0开始计算
            if(nums[i] != INT_MAX) {
                int curIndexNum = nums[i];//找到下一个元素坐标

                while(nums[curIndexNum] != INT_MAX) {//如果当前元素是最大值的话，说明已经访问过了不需要再次访问了，否则对其访问
                    curLen++;
                    int temp = curIndexNum;//记录下刚才访问的坐标
                    curIndexNum = nums[curIndexNum];//找到下一个元素坐标
                    nums[temp] = INT_MAX;//将刚才访问过的设置为INT_MAX
                }

                maxLen = max(maxLen,curLen);

            }
        }
        return maxLen;
    }
};*/

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxLen = 0;
        int curLen = 0;
        vector<bool> visied(nums.size());//代表着对应位置有没有被访问过

        for(int i=0; i<nums.size(); i++) {
            curLen = 0;
            int curIndexNum = nums[i];

            while(!visied[curIndexNum]) {//查看对应位置是否被访问过
                curLen++;
                int temp = curIndexNum;
                curIndexNum = nums[curIndexNum];
                visied[temp] = true;
            }
            maxLen = max(maxLen,curLen);
        }

        return maxLen;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5,4,0,3,1,6,2};

    int result = s.arrayNesting(nums);
    cout << result;
    return 0;
}



