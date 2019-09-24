
/*
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;
        for(int i = 0 ; i < t.size(); i++) {
            if(s[index] == t[i])
                index++;
        }
        
        return index == s.size();
    }
};
*/
/*
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;
        int n = t.size();
        for(char ch : s) {
            while(index < n && t[index] != ch)
                index++;
            if(index == n)
                return false;
            index++; // 若是当前字符相当，index需要向后移动一位
        }
        return true;
    }
};
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<int,vector<int>> hash;
        for(int i = 0; i < t.length(); i++) {
            hash[t[i]].push_back(i);
        }
        int prev = -1;
        for(char ch : s) {
            auto it = hash.find(ch);
            if(it == hash.end())
                return false;
            auto vec = it->second;
            int pos = upper_bound(vec.begin(), vec.end(), prev) - vec.begin(); // 找出vec中比prev大的位置
            if(pos == vec.size())
                return false;
            prev = vec[pos];
        }
        return true;
    }
};