class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string res = "";
        for(char ch : s) {
            if(ch == ']') {
                string temp = "";
                while(!st.empty() && st.top() != '[') {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop(); // 删除 对应的 [
                string num = ""; // 得到前面的数字
                while(!st.empty() && st.top() < 'a' && st.top() != '[') {
                    num = st.top() + num;
                    st.pop();
                }
                int n = stoi(num);
                while(n--) { // 重复n次
                    for(char t : temp)
                        st.push(t);
                }
            } else {
                st.push(ch);
            }
            
        }
        
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        
        return res;
    }
};