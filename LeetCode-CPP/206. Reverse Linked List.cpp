#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        /*if(head) {//创建一个链表，使用头插法。
            ListNode* tail = new ListNode(0);
            tail->val = head->val;

            ListNode* start = head->next;

            while(start) {
                ListNode* node = new ListNode(0);//创建一个新节点
                node->val = start->val;//对新节点赋值
                node->next = tail;
                tail = node;
                start = start->next;
            }
            return tail;
        } else {
            return NULL;
        }*/

        if(!head) {
            return NULL;
        }

        ListNode* p1 = head;
        ListNode* p2 = head->next;
        ListNode* p3;

        p1->next = NULL;

        while(p2) {
            p3 = p2->next;
            p2->next = p1;

            p1 = p2;
            p2 = p3;
        }

        return p1;

    }
};

int main() {
    Solution s;


    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    ListNode * p = s.reverseList(&node1);

    while(p) {
        cout << p->val;
        p = p->next;
    }

}

