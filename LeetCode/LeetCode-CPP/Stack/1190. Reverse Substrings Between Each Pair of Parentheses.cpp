/*
class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        stack<char> st;
        for(char ch : s) {
            if(ch != ')') {
                st.push(ch);
            } else {
                queue<char> q; // 使用队列来实现栈中元素的反转
                while(!st.empty() && st.top() != '(') {
                    q.push(st.top());
                    st.pop();
                }
                if(!st.empty()) // 删除 (
                    st.pop();
                while(!q.empty()) { // 把反转后（）中的内容再次添加到栈中
                    st.push(q.front());
                    q.pop();
                }
            }
        }
        while(!st.empty()) {
            char top = st.top();
            res = top + res;
            st.pop();
        }
        return res;
    }
};
*/

class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        stack<int> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') { // 记录上一个(的位置
                st.push(i);
            } else if(s[i] == ')') {
                int top = st.top(); // 找到上一个( 的位置
                reverse(s.begin() + top + 1, s.begin() + i); // 把()中间的所有内容进行反转
                st.pop();
            }
        }

        for(char ch : s) {
            if(ch != '(' && ch !=')')
                res += ch;
        }
        return res;
    }
};