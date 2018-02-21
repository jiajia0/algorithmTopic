#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int result = 0;
        int maxResult = candies.size()/2;// sister得到的最大糖果种类数目
        unordered_map<int,int> sister;

        for(int i=0;i<candies.size();i++) {
            if(sister[candies[i]]++ == 0) {// 如果没找到说明sisiter没有这种糖果
                result++;
                if(result == maxResult)// 当达到最大的数目时就不再查找
                    break;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> candies = {1,1,2,3};
    int result = s.distributeCandies(candies);
    cout << result;
    return 0;
}
