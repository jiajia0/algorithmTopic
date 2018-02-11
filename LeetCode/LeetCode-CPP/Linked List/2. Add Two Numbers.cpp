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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);//作为新链表的头结点
        ListNode* p = result;
        int carry = 0;//用来保留两个数相加之后进位的大小
        int sum,n1,n2;

        while(l1 || l2) {
            if(l1) {
                n1 = l1->val;
            }else {
                n1 = 0;
            }

            if(l2) {
                n2 = l2->val;
            }else {
                n2 = 0;
            }
            sum = n1 + n2 + carry;
            carry = sum / 10;

            p->next = new ListNode(sum % 10);
            p = p->next;

            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;

        }
        if(carry) {
            p->next = new ListNode(carry);
        }

        return result->next;

    }
};

int main() {
    Solution s;


    ListNode node1(1);
    ListNode node2(3);

    ListNode node3(9);
    ListNode node4(9);

    //node1.next = &node2;

    node3.next = &node4;

    ListNode* p = s.addTwoNumbers(&node1,&node3);

    while(p) {
        cout << p->val;
        cout << endl;
        p = p->next;
    }


}

