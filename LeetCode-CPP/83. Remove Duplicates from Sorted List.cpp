#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        /*ListNode* tail = new ListNode(-99999);
        ListNode* start = tail;

        while(head) {
            //下一个节点不为空并且当前节点和下个节点数字不一样 或者 下一个节点为空并且当前节点和新的节点最后一个不一样
            if(head->next && head->val != head->next->val || !head->next && head->val != tail->val) {//不相等的话加入新的链表
                ListNode* node = new ListNode(0);
                node->val = head->val;
                //cout << head->val;
                tail->next = node;
                tail = node;
            }
            head = head->next;
        }

        return start->next;*/

        if(!head) {
            return NULL;
        }

        ListNode * start = head;
        ListNode * tail = head->next;

        while(tail) {
            if(start->val == tail->val) {
                start->next = tail->next;
                tail = tail->next;
            } else {
                start = start->next;
            }

        }
        return head;
    }
};

int main() {
    Solution s;


    ListNode node1(0);
    ListNode node2(0);
    ListNode node3(0);
    ListNode node4(0);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    ListNode * p = s.deleteDuplicates(&node1);

    while(p) {
        cout << p->val;
        p = p->next;
    }

}

