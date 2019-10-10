class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int num = 0; // 用来记录到达A[i]时，对应的的十进制数字
        vector<bool> ans(A.size(), false);
        for(int i = 0; i < A.size(); i++) {
            // () %d == (?%d)%d
            // new_number%5 = ((old_number%5)*2 + d)%5;
            // Use the fact that (ab + c)%d is same as ((a%d)(b%d) + c%d)%d.
            num = ((num%5)*2 + A[i])%5;
            //cout << num << endl;
            if(num == 0) {
                ans[i] = true;
            }
        }
        return ans;
    }
};