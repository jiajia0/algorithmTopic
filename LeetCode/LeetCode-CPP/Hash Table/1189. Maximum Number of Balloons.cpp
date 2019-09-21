class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> nums(5,0);
        for(char ch : text) {
            if(ch == 'a')
                nums[0]++;
            if(ch == 'b')
                nums[1]++;
            if(ch == 'l')
                nums[2]++;
            if(ch == 'o')
                nums[3]++;
            if(ch == 'n')
                nums[4]++;
        }
        nums[2] /= 2;
        nums[3] /= 2;
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};