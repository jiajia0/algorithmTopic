/*
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hash;
        vector<int> al(256, 0);
        for(int i = 0; i < s.length(); ++i) {
            // 如果当前s[i]还没有映射
            if(!hash.count(t[i]) && !al[s[i]]) {
                hash[t[i]] = s[i];
                al[s[i]] = 1;
            } else {
                if(hash[t[i]] != s[i])
                    return false;
            }
        }
        
        return true;
    }
};
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for(int i = 0; i < s.length(); i++) {
            if(m1[s[i]] != m2[t[i]])
                return false;
            // i + 1 是为了避免出现0 ,因为 hash默认为0
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};