#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode temp(0);
        temp.next = head;//自己创造一个头结点
        ListNode* p = &temp;
        ListNode* q = head;

        while(q) {
            if(q->val == val) {
                p->next = q->next;
            } else {
                p = p->next;
            }
            q = q->next;
        }
        return temp.next;
    }
};

int main() {
    Solution s;
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(6);
    ListNode node4(3);
    ListNode node5(4);
    ListNode node6(5);
    ListNode node7(6);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;

    s.removeElements(&node1,6);
}
