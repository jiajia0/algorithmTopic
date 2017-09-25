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
    ListNode* removeNthFromEnd(ListNode* head, int n) {


        if(!head) {
            return NULL;
        }

        ListNode* result = new ListNode(0);
        result->next = head;
        ListNode* first = result;
        ListNode* second = result;

        n++;
        while(n) {
            n--;
            first = first->next;
        }

        while(first) {//直到first走到了尾部，那么first下一个就是我们需要删除的节点
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;//删除一个节日

        return result->next;


        /*if(!head) {
            return NULL;
        }

        stack<ListNode*> nodes;
        ListNode* result = new ListNode(0);

        while(head) {
            nodes.push(head);
            head = head->next;
        }

        while(!nodes.empty()) {
            n--;
            if(!n) {
                nodes.pop();
                if(nodes.empty()) break;
            }

            nodes.top()->next = result->next;
            result->next = nodes.top();
            nodes.pop();
        }
        return result->next;*/
    }
};

int main() {
    Solution s;


    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    ListNode* p = s.removeNthFromEnd(&node1,2);

    while(p) {
        cout << p->val;
        cout << endl;
        p = p->next;
    }

}

