/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> hash;
        for(int i : nums)
            hash[i]++;
        for(auto it = hash.begin();it != hash.end();it++)
            if(it->second == 1)
                return it->first;
        return 0;
    }
};
*/
// a和b的变化：
// x(1) : a = x, b = 0;
// x(2) : a = 0, b = x;
// x(3) : a = 0, b = 0;
// 所以如果一个字符出现一次，那么a=x，return x;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for(int n : nums) {
            a = (a^n) & ~b;
            b = (b^n) & ~a;
        }
        return a;
    }
};
