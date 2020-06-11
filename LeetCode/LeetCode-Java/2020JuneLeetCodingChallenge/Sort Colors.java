class Solution {
    public void sortColors(int[] nums) {
        int zero = 0;
        int two = nums.length - 1;
        int temp;
        for(int i = 0; i <= two; i++) {
            if(nums[i] == 0) {
                temp = nums[i];
                nums[i] = nums[zero];
                nums[zero++] = temp; 
            } else if(nums[i] == 2) {
                temp = nums[i];
                nums[i--] = nums[two];
                nums[two--] = temp;
            }
        }
    }
}