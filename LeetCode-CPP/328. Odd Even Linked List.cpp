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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) {
            return NULL;
        }

        ListNode* oddNode = NULL;//奇数节点
        ListNode* evenNode = NULL;//偶数节点
        ListNode* p1;
        ListNode* p2;
        int num = 1;

        while(head) {
            if(num%2 == 1) {//奇数节点
                if(!oddNode) {
                    oddNode = head;
                } else {
                    p1->next = head;
                }
                p1 = head;
            }
            if(num%2 == 0) {//偶数节点
                if(!evenNode) {
                    evenNode = head;
                } else {
                    p2->next = head;
                }
                p2 = head;
            }
            //cout << p1->val << ",";
            //cout << p2->val << endl;
            head = head->next;
            num++;
        }
        //cout << p1->val << ",";
        //cout << p2->val << endl;
        //cout << oddNode->val << ",";
        //cout << evenNode->val << endl;
        p1->next = evenNode;
        p2->next = NULL;
        return oddNode;
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

    ListNode* p = s.oddEvenList(&node1);

    while(p) {
        cout << p->val;
        cout << endl;
        p = p->next;
    }

}

