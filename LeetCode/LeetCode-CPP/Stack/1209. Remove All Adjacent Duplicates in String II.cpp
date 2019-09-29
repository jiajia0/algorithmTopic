class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(int i = 0; i < s.length(); i++) {
            if(!st.empty()) {
                if(st.top().first == s[i]) {
                    st.top().second++;
                    if(st.top().second == k) {
                        st.pop();
                    }
                } else {
                    st.push(make_pair(s[i], 1));
                }
            } else {
                st.push(make_pair(s[i], 1));
            }
        }
        
        string res = "";
        while(!st.empty()) {
            while(st.top().second--) {
                res = st.top().first + res;
            }
            st.pop();
        }
        return res;
    }
};