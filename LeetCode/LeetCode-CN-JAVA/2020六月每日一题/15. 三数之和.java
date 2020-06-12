class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        int n = nums.length;
        // 确定a之后，查找所有b和c的组合
        for(int a = 0; a < n && nums[a] <= 0; a++) {
            if(a > 0 && nums[a] == nums[a - 1]) { // 如果a已经查找过了，则直接跳过
                continue;
            }
            int c = n - 1;
            // 确定a和b，查找所有符合条件的c
            for(int b = a + 1; b < n && nums[a] + nums[b] <= 0 ; b++) {
                if(b > a + 1 && nums[b] == nums[b - 1]) { // 如果b查找过则不再查找
                    continue;
                }
                while(b < c && nums[a] + nums[b] + nums[c] > 0) {
                    c--;
                }
                // b==c说明b后面的所有c，都是a+b+c>0，那么随着b和c的增加，则不会出现a+b+c==0的情况
                if(b == c) {
                    break;
                }
                // <0不处理，因为可能随着后边b的增加满足等于
                if(nums[a] + nums[b] + nums[c] == 0) {
                    ArrayList<Integer> subans = new ArrayList<>();
                    subans.add(nums[a]);
                    subans.add(nums[b]);
                    subans.add(nums[c]);
                    ans.add(subans);
                }
            }
        }
        return ans;
    }
}