#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        ListNode* result = new ListNode(0);
        ListNode* temp;
        ListNode* tail;

        while(head) {
            temp = head->next;//将第一个节点隔离开来用来计算
            tail = result;//从新链表的第一个节点开始遍历

            while(tail->next && tail->next->val < head->val) {//将tail移动到所要插入节点的前面
                tail = tail->next;
            }

            head->next = tail->next;//将节点插入到中间
            tail->next = head;

            head = temp;
        }

        return result->next;
    }
};

int main() {
    Solution s;


    ListNode node1(10);
    ListNode node2(2);
    ListNode node3(31);
    ListNode node4(14);
    ListNode node5(5);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    ListNode* p = s.insertionSortList(&node1);

    while(p) {
        cout << p->val;
        cout << endl;
        p = p->next;
    }

}

