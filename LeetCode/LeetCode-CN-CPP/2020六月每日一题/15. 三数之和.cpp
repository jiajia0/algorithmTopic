class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // 首先进行排序
        for(int a = 0; a < nums.size(); a++) { // 先确定一个a，然后找出在a确定下的所有b、c组合
            if(a > 0 && nums[a] == nums[a - 1]) { // 如果当前的a已经查找过了，跳过
                continue;
            }
            int c = nums.size() - 1; // a+b+c=0时，当a确定了，b随着循环增大，如果要满足公式，则c随着循环变小，所以c从后面还是遍历
            for(int b = a + 1; b < nums.size(); b++) { // 再确定一个b , 此时确定了a和b，然后找到所有符合条件的c
                if(b > a + 1 && nums[b] == nums[b - 1]) { // 如果当前的a、b已经查找过了，跳过
                    continue;
                }
                // c的位置不可能比b小，如果此时a+b+c>0则说明c过大，需要小一点
                while(b < c && nums[a] + nums[b] + nums[c] > 0) {
                    c--;
                }
                // 跳出上面while可能是b==c or a+b+c <= 0
                // 如果是b==c ，说明b后面的所有的c都是a+b+c>0，并且随着b的增大，后续所有的式子都会>0
                if(b == c) {
                    break;
                }
                // 满足条件。<0时不用处理，因为随着b增大可能就满足了
                if(nums[a] + nums[b] + nums[c] == 0) {
                    ans.push_back({nums[a],nums[b],nums[c]});
                }
            }
        }
        return ans;
    }
};