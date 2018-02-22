#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<int> stk;// 用来保存之前的气温是第几天的

        // 从尾到头遍历
        for(int i=temperatures.size()-1;i>=0;i--) {
            while(!stk.empty() && temperatures[i] >= temperatures[stk.top()])// 如果当前的气温比栈中的气温高，则出栈
                stk.pop();
            // 如果栈中为空，则说明后面的天气没有比现在高的，放入0，
            // 如果不为空则说明后面的天气存在比现在高的，则查看上个比之前高的天气是第几天的。
            ans[i] = stk.empty() ? 0 : stk.top() - i ;
            stk.push(i);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> temperatures = {89,62,70,58,47,47,46,76,100,70};
    vector<int> result = s.dailyTemperatures(temperatures);
    for(int i : result ) {
        cout << i << " ";
    }
    return 0;
}
