class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        if(pushed.size() != popped.size())
            return false;
        int i = 0;
        for(int n : pushed) {
            st.push(n); // 先把pushed中的数字存入栈中
            while(!st.empty() && st.top() == popped[i]) { //栈顶元素等于当前需要出栈的元素,则进行出栈操作 
                st.pop();
                i++; // 出栈的index向后移动
            }
        }
        return st.size() == 0;
    }
};