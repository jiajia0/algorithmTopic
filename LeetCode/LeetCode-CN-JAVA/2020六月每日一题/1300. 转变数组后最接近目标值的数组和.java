class Solution {
    public int findBestValue(int[] arr, int target) {
        // C++ 用的二分，这里使用平均值
        Arrays.sort(arr); // 首先进行排序
        int sum = 0;
        for(int i = 0 ; i < arr.length; i++) {
            int x = (target - sum) / (arr.length - i); // 计算出期望值与实际值的平均值
            if(arr[i] > x) { // 由于是递增关系，如果当前的数值比平均值还大，则不可能更接近了
                double r =  (double)(target - sum) / (arr.length - i);
                return r - x > 0.5 ? x + 1 : x;
            }
            sum += arr[i];
        }
        return arr[arr.length - 1]; // 说明数组中所有的元素都小于等于评平均值，那么数组不需要改动，因为只会越改越小
    }
}