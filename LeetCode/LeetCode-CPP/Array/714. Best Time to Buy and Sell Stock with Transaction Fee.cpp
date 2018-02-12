#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0;// 用来统计当前的利润现金
        int hold = -prices[0];// 用来计算当前的股票
        for(int i=1; i<prices.size(); i++) {
            cash = max(cash, prices[i] + hold - fee);// 比较当前现金和如果出售手头股票赚到的利润
            hold = max(hold,cash - prices[i]);// 比较当前的股票和如果购买股票之后手上剩下的钱
        }
        return cash;
    }
};


int main() {
    Solution s;
    vector<int> nums = {1,3,7,5,10,3};

    int result = s.maxProfit(nums,3);
    cout << result;
    return 0;
}



