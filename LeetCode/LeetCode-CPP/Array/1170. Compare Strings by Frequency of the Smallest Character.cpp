class Solution {
public:
    /*
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> nums(words.size(), 0); // 用来统计f(words[i])
        for(int i = 0; i < words.size(); i++) {
            nums[i] = f(words[i]);
        }
        
        vector<int> ans(queries.size(), 0);
        // 下面的可以使用二叉搜索进行优化
        for(int i = 0; i < queries.size(); i++) {
            int cur_num = f(queries[i]); // 找出当前单词出现的次数
            for(int n : nums) {
                if(n > cur_num)
                    ans[i]++;
            }
        }
        return ans;
    }
    */
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> words_nums(words.size(), 0); // 用来统计f(words[i])
        vector<int> queries_nums(queries.size(), 0);
        for(int i = 0; i < words.size(); i++) {
            words_nums[i] = f(words[i]);
        }
        for(int i = 0; i < queries.size(); i++) {
            queries_nums[i] = f(queries[i]);
        }
        
        sort(words_nums.begin(), words_nums.end()); // 进行排序
        
        vector<int> ans(queries.size(), 0);
        
        for(int i = 0; i < queries.size(); i++) {
            int low = 0, high = words_nums.size() - 1;
            while(low < high) {
                int mid = low + (high - low) / 2;
                if(words_nums[mid] <= queries_nums[i]) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            // 此时low和high为第一个比queries_nums[i]大的下标，或者没有比当前数字大的，就返回最后一个位置
            ans[i] = words_nums[low] > queries_nums[i] ? words_nums.size() - low : 0;
        }
        
        return ans;
    }
    
    // 统计word中最小字符出现的次数
    int f(string word) {
        vector<int> al(26, 0);
        for(char ch : word) {
            al[ch - 'a']++;
        }
        for(int i = 0; i < al.size() ;i++){
            if(al[i] != 0)
                return al[i];
        }
        return 0;
    }
};