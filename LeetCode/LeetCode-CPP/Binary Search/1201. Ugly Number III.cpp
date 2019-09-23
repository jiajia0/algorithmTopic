class Solution {
public:
    int nthUglyNumber(int n, int A, int B, int C) {
        int lo = 1, hi = 2 * 1e9; // ´ð°¸µÄ·¶Î§
        long a = (long) A, b = (long) B, c = (long) C;
        long ab = a*b / __gcd(a,b);
        long ac = a*c / __gcd(a,c);
        long bc = b*c / __gcd(b,c);
        long abc = a*bc / __gcd(a,bc);
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = mid/a + mid/b + mid/c - mid/bc - mid/ac - mid/ab + mid/abc;
            if(cnt < n)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
};