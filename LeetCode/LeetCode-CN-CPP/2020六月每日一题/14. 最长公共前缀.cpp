class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }
        string ans = strs[0]; // 默认第一个字符串为公共前缀
        for(int i = 1; i < strs.size(); i++) {
            string temp_ans = "";
            // 对于当前的前缀和下一个字符串，找到公共部分作为公共前缀
            for(int j = 0 ; j < min(strs[i].size(), ans.size()); j++) {
                if(ans[j] == strs[i][j]) {
                    temp_ans += ans[j];
                } else {
                    break;
                }
            }
            ans = temp_ans;
            if(ans == "") {
                break;
            }
        }
        return ans;
    }
};