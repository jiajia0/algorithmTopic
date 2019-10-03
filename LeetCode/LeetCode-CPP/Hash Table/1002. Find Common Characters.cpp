class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> nums(26, INT_MAX); // 用来统计所有单词中，每个字母出现的最少次数
        vector<string> res;
        for(string str : A) {
            vector<int> cnt(26, 0);
            for(char ch : str) { // 统计当前单词各个字母出现的次数
                cnt[ch - 'a']++;
            }
            for(int i = 0; i < 26; i++) {
                nums[i] = min(cnt[i], nums[i]); // 记录下26个字母出现次数最少的
            }
        }
        
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < nums[i]; j++) {
                res.push_back(string(1, i + 'a'));
            }
        }
        return res;
    }
};