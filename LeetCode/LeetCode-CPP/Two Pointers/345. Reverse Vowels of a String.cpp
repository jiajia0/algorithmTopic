class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;
        unordered_map<char,int> m;
        m['a'] = 1;
        m['e'] = 1;
        m['i'] = 1;
        m['o'] = 1;
        m['u'] = 1;
        m['A'] = 1;
        m['E'] = 1;
        m['I'] = 1;
        m['O'] = 1;
        m['U'] = 1;
        while(left < right) {
            
            while(!m.count(s[left]) && left < right)
                left++;
            while(!m.count(s[right]) && left < right)
                right--;
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};