#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int peak, valley ;
        peak = valley = prices[0];
        int maxProfit = 0;
        int i=0;
        while(i < prices.size()-1) {
            while(i<prices.size()-1 && prices[i] >= prices[i+1]) {//找到价格最低的那一天
                i++;
            }
            valley = prices[i];
            while(i<prices.size()-1 && prices[i] <= prices[i+1]) {//找到后面紧跟的价格高的一天
                i++;
            }
            peak = prices[i];
            maxProfit += peak - valley;//计算此时的利润
        }
        return maxProfit;
    }
};

/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for(int i=1; i<prices.size();i++) {
            if(prices[i] > prices[i-1]) {
                maxProfit += prices[i] - prices[i-1];
            }
        }
        return maxProfit;
    }
};*/

int main() {
    Solution s;
    vector<int> nums;

    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(4);

    int result = s.maxProfit(nums);
    cout << result;
    return 0;
}



