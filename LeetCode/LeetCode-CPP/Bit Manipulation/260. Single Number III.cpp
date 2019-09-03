/*class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int> ha;
        vector<int> ans;
        for(int n : nums) {
            ha[n]++;
        }
        for(auto it=ha.begin();it!=ha.end();it++) {
            if(it->second == 1)
                ans.push_back(it->first);
        }
        return ans;
    }
};
*/
// 所有的数字进行异或操作之后，相同的数字自然抵消为0.
// 不同的两个数字进行异或，在不为0的位置上，也就是1的位置上，是两个数字异或得到的1，所以在该位置上一个为1，一个为0。
// 所以只要根据这个1，对两个数字分别进行异或即可。
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        vector<int> res(2,0);
        for(int i : nums)
            diff ^= i;
        diff &= -diff; // 获取到最后一个1
        int a = 0, b = 0;
        for(int i : nums)
            if((diff & i) == 0)
                a ^= i;
            else
                b ^= i;
        res[0] = a;
        res[1] = b;
        return res;
    }
};
