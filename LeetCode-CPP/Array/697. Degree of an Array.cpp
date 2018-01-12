#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int maxCount = 0;//数字出现的最多次数，也就是度数
        unordered_map<int,int> numCount;//用来存放每个数字出现的次数
        unordered_set<int> maxNums;//存放最大次数的数字

        for(int i=0;i<nums.size();i++) {
            numCount[nums[i]]++;//对应的次数加一

            if(numCount[nums[i]] > maxCount) {//交换位置，并清空maxNums数组，存放新的最大值
                maxCount = numCount[nums[i]];
                maxNums.clear();
                maxNums.insert(nums[i]);
            }
            if(numCount[nums[i]] == maxCount) {//如果相等的话,把新的数字添加进去
                maxNums.insert(nums[i]);
            }
        }

        int startIndex = -1;
        int endIndex = -1;
        int minLen = -1;

        for(int num : maxNums) {//遍历所有度数最大的数字，找到距离最短的
            startIndex = -1;
            endIndex = -1;
            for(int i=0; i<nums.size(); i++) {
                if(nums[i] == num) {
                    if(-1 == startIndex) {
                        startIndex = i;
                    }
                    if(i >= endIndex) {
                        endIndex = i;
                    }
                }
            }
            minLen = (minLen < 0) ? (endIndex-startIndex+1) : min(endIndex-startIndex+1,minLen);
            //cout << startIndex << "," << endIndex << endl;
            //cout << (endIndex-startIndex+1) << endl;
        }

        return minLen;
    }
};*/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums.size();
        }
        int minLen = 0;//最小的为1
        int degree = 0;//最小的度为1

        unordered_map<int,pair<int,int>> ans;//用来存储元素和该元素开始下标和出现的次数

        for(int i=0; i<nums.size(); i++) {
            ans[nums[i]].second++;//出现的次数加一
            if(ans[nums[i]].second == 1) {//代表该元素首次出现
                //cout << "数字：" << nums[i] << ",开始的坐标" << i << endl;
                ans[nums[i]].first = i;//记录开始的坐标
            }

            if(ans[nums[i]].second > degree) {//如果此时出现的次数大于数组中的最高度数
                degree = ans[nums[i]].second;//重置最高度数
                minLen = i - ans[nums[i]].first + 1;//当前位置减去开始位置得到中间长度
                //cout << "当前坐标" << i << "，开始坐标：" << ans[nums[i]].first << endl;
            } else if(ans[nums[i]].second == degree) {//如果度数相等则需要比较哪一个比较短
                minLen = min(minLen,i - ans[nums[i]].first + 1);
            }
        }

        return minLen;
    }
};



int main() {
    Solution s;
    vector<int> nums = {1, 2, 2, 3, 1};

    int result = s.findShortestSubArray(nums);
    cout << result;
    return 0;
}



