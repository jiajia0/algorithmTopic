/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        vector<int> res;
        
        int i = 0;
        
        while(head) {
            res.push_back(head->val); // 先加入一个新的节点
            // 判断对应index上的元素是否小与当前节点，若小与则把对应index位置上的元素设置为当前节点值
            while(!st.empty() && res[st.top()] < head->val) {
                res[st.top()] = head->val;
                st.pop();
            }
            st.push(i); // 存放对应的index
            i++;
            head = head->next;
        }
        
        // 把没有出栈的元素对应的index设置为0
        while(!st.empty()) {
            res[st.top()] = 0;
            st.pop();
        }
        
        return res;
    }
};

*/

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* curr = head;
        vector<int> res;
        while(curr) {
            res.push_back(curr->val);
            curr = curr->next;
        }
        
        stack<int> st;
        for(int i = res.size() - 1; i >= 0; i--) {
            int curr_num = res[i];
            // 把栈中比当前节点小的都给pop掉
            while(!st.empty() && st.top() <= res[i])
                st.pop();
            if(st.empty()) // 若栈为空，则说明没有比当前节点更大的了
                res[i] = 0;
            else
                res[i] = st.top();
            st.push(curr_num); // 把当前数字推入到栈中
        }
        return res;
    }  
};