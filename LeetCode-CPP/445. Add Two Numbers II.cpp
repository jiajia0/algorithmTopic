#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* result = new ListNode(0);
        stack<int> nodes1;
        stack<int> nodes2;
        int carry = 0;
        int sum;

        while(l1 || l2) {

            if(l1) {
                nodes1.push(l1->val);
                l1 = l1->next;
            }

            if(l2) {
                nodes2.push(l2->val);
                l2 = l2->next;
            }
        }

        int n1,n2;
        while(!nodes1.empty() || !nodes2.empty()) {//因为两个栈的元素一样多


            if(nodes1.empty()) {
                n1 = 0;
            } else {
                n1 = nodes1.top();
                nodes1.pop();
            }

            if(nodes2.empty()) {
                n2 = 0;
            } else {
                n2 = nodes2.top();
                nodes2.pop();
            }

            //cout << n1 << "," << n2 << endl;


            sum = n1 + n2 + carry;

            //cout << "sum:" << sum << endl;

            carry = sum / 10;//进的位数

            result->val = sum % 10;//最后面一个节点赋值
            ListNode* node = new ListNode(0);
            node->next = result;
            result = node;
        }

        if(carry) {
            result->val = carry;
            return result;
        } else {
            return result->next;
        }
    }
};

int main() {
    Solution s;


    ListNode node1(7);
    ListNode node2(2);
    ListNode node3(4);
    ListNode node4(3);

    ListNode node5(5);
    ListNode node6(6);
    ListNode node7(4);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    node5.next = &node6;
    node6.next = &node7;

    ListNode* p = s.addTwoNumbers(&node1,&node5);
    while(p) {
        cout << p->val << endl;
        p = p->next;
    }

}

