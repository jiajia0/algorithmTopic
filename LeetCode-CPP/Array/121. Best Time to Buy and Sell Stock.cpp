#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;//最大的利润
        int minPrice = INT_MAX;//最小的价格

        for(int i=0;i<prices.size();i++) {
            if(prices[i] < minPrice) {//替换最小的价格
                minPrice = prices[i];
            }
            if(prices[i]-minPrice > maxProfit) {// 替换最大的利润
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;//最大的利润
        int curProfit = 0;//当前的利润

        for(int i=1;i<prices.size();i++) {
            curProfit = max(0,curProfit + prices[i] - prices[i-1]);//计算最近两天的利润加上之前的利润是多少
            maxProfit = max(maxProfit,curProfit);//更换最大的利润
        }
        return maxProfit;
    }
};


int main() {
    Solution s;
    vector<int> nums = {7, 1, 5, 3, 6, 4};

    int result = s.maxProfit(nums);
    cout << result;
    return 0;
}




