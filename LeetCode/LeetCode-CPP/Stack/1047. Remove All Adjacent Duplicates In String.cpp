/*
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> s;
        for(char ch : S) {
            if(s.empty()) {
                s.push(ch);
            } else {
                char temp = s.top();
                if(temp == ch)
                    s.pop();
                else
                    s.push(ch);
            }
        }
        string res = "";
        while(!s.empty()) {
            char temp = s.top();
            s.pop();
            res = temp + res;
        }
        return res;
    }
};
*/
// 直接把string类型当作栈来用
class Solution {
public:
    string removeDuplicates(string S) {
        string res = "";
        for(char ch : S) {
            if(!res.empty() && res.back() == ch) {
                res.pop_back();
            } else {
                res.push_back(ch);
            }
        }
        return res;
    }
    
};