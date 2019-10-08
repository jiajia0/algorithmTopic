/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
public:
    
    TreeNode* dfs(int left, int right, vector<int>& nums) {
        if(left > right)
            return NULL;
        int cur = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[cur]);
        node->left = dfs(left, cur - 1, nums);
        node->right = dfs(cur + 1, right, nums);
        return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        vector<int> nums;
        while(head) {
            nums.push_back(head->val);
            head = head->next;
        }
        return dfs(0,nums.size() - 1, nums);
    }
};
*/
/*
class Solution {
public:
    
    TreeNode* dfs(ListNode* head, ListNode* tail) {
        if(head == tail)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        // 使用快慢指针找到中点
        while(fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* node = new TreeNode(slow->val);
        node->left = dfs(head, slow);
        node->right = dfs(slow->next, tail);
        return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        return dfs(head, NULL);
    }
};
*/

class Solution {
public:
    ListNode* g_head;
    int getListSize(ListNode* head) {
        ListNode* p = head;
        int c = 0;
        while(p) {
            c++;
            p = p->next;
        }
        return c;
    }
    
    TreeNode* dfs(int l, int r) {
        if(l > r) {
            return NULL;
        }
        //cout << g_head->val << endl;
        int mid = (l + r) / 2;
        TreeNode* left = dfs(l, mid - 1);
        TreeNode* node = new TreeNode(g_head->val);
        g_head = g_head->next;
        node->left = left;
        node->right = dfs(mid + 1, r);
        return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        int len = getListSize(head);
        g_head = head;
        // len - 1 ：从0开始，或者1，len也行
        return dfs(0, len - 1);
    }
};