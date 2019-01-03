#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;
        while( fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
            //cout << slow->val << " ";
        }
        return slow;
    }
};

int main() {
    Solution s;

    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    //ListNode node6(6);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    //node5.next = &node6;

    ListNode* p = s.middleNode(&node1);

    while(p) {
        cout << p->val;
        cout << endl;
        p = p->next;
    }


}
