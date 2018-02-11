#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());//排序
        int count = nums.size();
        return max(nums[count-1]*nums[count-2]*nums[count-3],nums[count-1]*nums[0]*nums[1]);//需要注意可能会有负数的情况
    }
};*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int firstPosNum = INT_MIN;//最大的正数
        int secondPosNum = INT_MIN;//第二大的正数
        int thirdPosNum = INT_MIN;//第三大的正数
        int firstNegNum = INT_MAX;//最小的负数
        int secondNegNum = INT_MAX;//第二小的负数

        for (int i=0; i < nums.size(); i++) {
            if(num[i] > firstPosNum) {//替换大的
                thirdPosNum = secondPosNum;
                secondPosNum = firstPosNum;
                firstPosNum = num[i];
            } else if(num[i] > secondPosNum) {
                thirdPosNum = secondPosNum;
                secondPosNum = num[i];
            } else if (num[i] > thirdPosNum) {
                thirdPosNum = num[i];
            }

            if(num[i] < firstNegNum) {//替换小的
                secondNegNum = firstNegNum;
                firstNegNum = num[i];
            } else if(num < secondNegNum) {
                secondNegNum = num[i];
            }
        }

        //cout << firstPosNum << "," << secondPosNum << "," << thirdPosNum << endl;
        //cout << firstNegNum << "," << secondNegNum << endl;

        int Pos = firstPosNum*secondPosNum*thirdPosNum;
        int Neg = firstPosNum*firstNegNum*secondNegNum;

        return max(Pos,Neg);

    }
};


int main() {
    Solution s;
    vector<int> num;
    num.push_back(-1);
    num.push_back(-2);
    num.push_back(1);
    int ret = s.maximumProduct(num);
    cout << ret;
}


