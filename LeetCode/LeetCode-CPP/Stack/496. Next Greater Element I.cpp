/*
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int n : nums1) {
            cout << n << endl;
            // 找到对应位置的iterator
            vector<int>::iterator it = find(nums2.begin(), nums2.end(), n);
            int flag = 1;
            while(it != nums2.end()) {
                if(*it > n) {
                    res.push_back(*it);
                    flag = 0;
                    break;
                }
                it++;
            }
            if(flag)
                res.push_back(-1);
        }
        return res;
    }
};
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> m;
        for(int n : nums2) {
            // 栈顶元素不为空，并且小于当前值 , 如果栈中有元素，并且都比当前值小，那么都设置为n
            // eg：6 5 4 3 2 1 7
            while(!st.empty() && st.top()<=n) {
                m[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }
        vector<int> res;
        for(int n : nums1) {
            if(m.count(n)) {
                res.push_back(m[n]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
    
};