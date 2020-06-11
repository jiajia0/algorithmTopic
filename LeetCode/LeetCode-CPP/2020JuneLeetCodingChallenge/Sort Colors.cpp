class Solution {
public:
    void sortColors(vector<int>& nums) {
        int two = nums.size() - 1; // 从后向前记录2的位置
        int zero = 0;   // 从前向后记录0的位置
        for(int i = 0; i <= two; i++) {
            if(nums[i] == 0) { // 如果当前位置上是0，则把0放入到对应位置上
                swap(nums[i], nums[zero++]); // zero索引向后移动一位
            } else if(nums[i] == 2) { // 如果是2，则放到2的位置上
                swap(nums[i--], nums[two--]); // 注意这里2进行交换完之后还需要重新对当前位置进行比较，如果2和0交换完之后，需要对当前的0再次比较。上面0的情况不用考虑，因为是从前向后遍历，前面的肯定处理完了，不会有2的出现，并且有0的话肯定会在对应位置上。
            }
        }
    }       
};