class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int res = 0;
        for(string op : ops) {
            if(op == "C") { // 最后一个分数无效
                int top = st.top();
                res -= top;
                st.pop();
                continue;
            }
            if(op == "D") { // 最后一个分数的两倍加到最终结果中，并且两倍的分数需要放入栈中
                int top = st.top() * 2;
                res += top;
                st.push(top);
                continue;
            }
            if(op == "+") { // 得到栈顶两个的数字，相加得到新的分数
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.pop();
                st.push(top2);
                st.push(top1);
                st.push(top1 + top2);
                res += (top1 + top2);
                continue;
            }
            // 普通的数字，直接相加
            st.push(stoi(op));
            res += stoi(op);
            
        }
        return res;
    }
};