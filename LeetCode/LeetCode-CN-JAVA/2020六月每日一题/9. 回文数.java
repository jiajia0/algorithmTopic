class Solution {
    public boolean isPalindrome(int x) {
        // 小于0肯定不是回文数
        // 最后一位为0，那么第一位必须为0，所以此时x应该为0
        if(x < 0 || (x%10 == 0 && x!=0)) {
            return false;
        }

        int reversedNumber = 0;
        while(x > reversedNumber) {
            reversedNumber = reversedNumber * 10 + x%10;
            x /= 10;
        }
        return reversedNumber == x || reversedNumber/10 == x;
    }
}