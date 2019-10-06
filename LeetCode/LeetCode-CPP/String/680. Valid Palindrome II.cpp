class Solution {
public:
    bool isPalindrome(string s, int low, int high) {
        for(low;low < high; low++, high--) {
            if(s[low] != s[high])
                return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        for(int i = 0 ; i < s.length() / 2; i++) {
            // 如果当前不匹配的话，分别去掉左边的或右边的进行检查
            if(s[i] != s[s.length() - 1 - i]) {
                return isPalindrome(s, i, s.length() - 1 - i - 1) || isPalindrome(s, i + 1, s.length() - 1 - i);
            }
        }
        return true;
    }
};