class Solution {
public:
    // 两个指针，一个指向需要交换的位置，一个向后寻找可以交换的元素
    int removeElement(vector<int>& nums, int val) {
        int n=0;
        for(int i = 0; i < nums.size(); i++) {
            // 进行交换
            if(nums[i] != val) {
                swap(nums[i], nums[n]);
                n++;
            }
        }
        return n;
    }
};