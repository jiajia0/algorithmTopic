/*
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> res(nums.size(), -1);
        for(int i = 2*nums.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i%nums.size()]) { // 把栈中小于当前元素都出栈
                st.pop();
            }
            res[i%nums.size()] = st.empty() ? -1 : st.top();
            st.push(nums[i%nums.size()]);
            // 从后向前存入栈中，所以从栈顶到栈底的顺序就是数组中从前到后的顺序
        }
        return res;
    }
};
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> res(nums.size(), INT_MAX);
        // 先把后面比当前元素大的找出来
        for(int i = nums.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            if(!st.empty()) {
                res[i] = st.top();
            }
            st.push(nums[i]);
        }
        // 重新查找一遍，把INT_MAX位置上的元素，从头开始查找一遍
        for(int i = 0 ; i < nums.size(); i++) {
            if(res[i] != INT_MAX)
                continue;
            else {
                int flag = 1;
                for(int j = 0; j < i; j++) {
                    if(nums[j] > nums[i]) {
                        res[i] = nums[j];
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                    res[i] = -1;
            }
        }
        
        return res;
    }
};