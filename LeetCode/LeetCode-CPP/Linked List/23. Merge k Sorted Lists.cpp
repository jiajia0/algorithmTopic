/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(0);
        ListNode* p;
        vector<int> nums;
        for(auto list : lists) {
            p = list;
            while(p != NULL) {
                nums.push_back(p->val);
                p = p->next;
            }
        }
        sort(nums.begin(), nums.end());
        p = res;
        for(int n : nums) {
            ListNode* node = new ListNode(n);
            res->next = node;
            res = node;
        }
        return p->next;
    }
};