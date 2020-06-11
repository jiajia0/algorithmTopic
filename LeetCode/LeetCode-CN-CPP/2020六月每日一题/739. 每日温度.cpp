class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(),0);
        stack<int> stk;

        for(int i = T.size() - 1; i >= 0; i--) {
            // 栈中只需要保存比当前气温高的位置
            while(!stk.empty() && T[i] >= T[stk.top()]) {
                stk.pop(); // 出栈
            }
            // 如果栈中为空，则说明没有比当前气温高，否则计算出最近比当前大的位置与当前的位置
            result[i] = stk.empty() ? 0 : stk.top() - i;
            stk.push(i);
        }

        return result;
    }
};