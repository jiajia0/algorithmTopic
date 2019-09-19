class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 最小的positive为1
        if(nums.size() == 0)
            return 1;
        for(int i = 0; i < nums.size();) {
            // 如果发生交换的话，不会向后移动，因为当前位置交换完之后可能还需要再次交换
            if(nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1]) {
                i++;
                continue;
            }
            
            // 把当前位置上的value，放到index为value-1的位置上去
            int temp = nums[i]; // 当前位置上的元素
            nums[i] = nums[temp - 1]; // 当前位置上的数字作为index，查找到对应的数字进行交换
            nums[temp - 1] = temp;     
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return nums.size() + 1;
        
    }
};