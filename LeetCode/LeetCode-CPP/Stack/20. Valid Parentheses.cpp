class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s) {
            if(!st.empty()) {
                char top = st.top();
                if((top=='(' && ch == ')') || (top=='{' && ch=='}') || (top=='[' && ch==']')) {
                    st.pop();
                } else
                    st.push(ch);
            } else 
                st.push(ch);
        }
        
        return st.size() == 0;
    }
};