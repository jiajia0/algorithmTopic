class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> m;
        unordered_map<char,int> used;
        int res = 0;
        int flag;
        for(char ch : chars)
            m[ch]++;
        
        for(string word : words) {
            flag = 1;
            used.clear();
            for(char ch : word) {
                used[ch]++;
                if(used[ch] > m[ch]) {
                    flag = 0;
                    break;
                }  
            }   
            if(flag)
                res += word.length();
        }
        return res;
    }
};