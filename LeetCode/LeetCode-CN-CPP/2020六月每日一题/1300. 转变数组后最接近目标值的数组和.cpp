class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end()); // 先进行排序
        vector<int> prefix; // prefix 的i保存的是arr中i及i之前的和
        for(int i = 0; i < arr.size(); i++) {
            int sub_sum = i == 0 ? arr[i] : arr[i] + prefix[i-1];
            prefix.push_back(sub_sum);
            //cout << prefix[i] << " ";
        }
        
        int ans = 0;
        int max = *max_element(arr.begin(), arr.end()); // 得到数组中的最大值
        int diff = target; // 计算目前的差距，初始值为最大的可能差距

        // 答案会在1-max之间
        for(int i = 1; i <= max; i++) {
            int loc = lower_bound(arr.begin(), arr.end(), i) - arr.begin(); // 找到大于或者等于i的第一个位置
            int cur = loc == 0 ? arr.size() * i :  prefix[loc - 1] + (arr.size() - loc) * i; // 如果替换后的数值大小
            //cout << "cur:" << cur << ", loc "<< loc << " i:" << i << " " << ", prefix:" << prefix[loc];
            if(abs(cur - target) < diff) {
                diff = abs(cur - target);
                ans = i;
            }
        }
        return ans; 
    }
};