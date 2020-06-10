class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int origin_num = x;
        long reverse_num = 0;
        while(x != 0) {
            reverse_num *= 10;
            reverse_num += x%10;
            x /= 10;
        }
        if(reverse_num == origin_num) {
            return true;
        }
        return false;
    }
};