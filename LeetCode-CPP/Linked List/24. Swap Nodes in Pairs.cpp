#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        queue<ListNode*> nodes;
        ListNode* start,* tail;

        while(head) {
            if(head->next) {
                nodes.push(head->next);
                //cout << "next:" << head->next->val << ",";
            }
            nodes.push(head);
            //cout << "head:" << head->val << endl;

            if(head->next) {
                head = head->next->next;
            } else {
                break;
            }
        }

        start = nodes.front();
        tail = start;
        nodes.pop();
        while(!nodes.empty()) {
            //cout << "queue:" << nodes.front()->val << ",";
            tail->next = nodes.front();
            tail = nodes.front();
            nodes.pop();
        }
        tail->next = NULL;
        return start;

        /*ListNode* tail = NULL;//用来指向交换后最后一个
        ListNode* temp;//用来标记两个需要交换的节点的第二个，head是第一个
        ListNode* result = head->next;


        while(head->next) {
            temp = head->next;
            head->next = temp->next;
            temp->next = head;

            if(tail) {
                tail->next = temp;
                tail = head;
            } else {
                tail = head;
            }
            head = head->next;
            if(!head) {
                break;
            }

        }
        return result;*/
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
    //node2.next = &node3;
    //node3.next = &node4;
    //node4.next = &node5;

    ListNode* p = s.swapPairs(&node1);

    while(p) {
        cout << p->val;
        cout << endl;
        p = p->next;
    }

}

