class Solution {
public:
    // isalnum 
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while(left < right) {
            while(left < right && (s[left] < '0' ||(s[left] > '9' && s[left] < 'A') || s[left] > 'z' || (s[left] > 'Z' && s[left] < 'a'))) {
                left++;
            }
            while(left < right && (s[right] < '0' ||(s[right] > '9' && s[right] < 'A') || s[right] > 'z' || (s[right] > 'Z' && s[right] < 'a'))) {
                right--;
            }
            if(tolower(s[left]) == tolower(s[right])) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
};