class Solution {
public:
    bool isValid(string S) {
        stack<char> st;
        for(char ch : S) {
            if(ch == 'c') {
                if(st.size() < 2 || st.top() != 'b') {
                    return false;
                } else {
                    char b = st.top(); // b;
                    st.pop();
                    if(st.top() == 'a') {
                        st.pop();
                    } else {
                        return false;
                    }
                }
            } else {
                st.push(ch);
            }
        }
        
        return st.size() == 0;
    }
};