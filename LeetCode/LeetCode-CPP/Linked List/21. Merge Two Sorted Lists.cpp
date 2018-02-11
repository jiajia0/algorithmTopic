#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;//用来指向l1
        ListNode* p2 = l2;//用来指向l2
        ListNode* tail;//用来表示当前最后一个节点
        int flag;//用来标记第一个数值谁大谁小，用来最后确定返回值。
        if(!p1) {//如果l1为空，直接返回l2
            return p2;
        } else if(!p2) {//l2为空，返回l1
            return p1;
        } else {
            if(p1->val<=p2->val) {//比较第一个节点的大小。
                tail = p1;
                p1 = p1->next;
                flag = 1;
            } else {
                tail = p2;
                p2 = p2->next;
                flag = 2;
            }

            while(p1 && p2) {
                if(p1->val <= p2->val) {//如果p1的数比p2的小，让tail指向p1,并且继续遍历。
                    tail->next = p1;
                    tail = p1;
                    p1 = p1->next;
                } else {//如果p2比p1的数小，tail指向这里
                    tail->next = p2;
                    tail = p2;
                    p2 = p2->next;
                }
            }

            if(!p1) {//如果此时p1指向空了，直接将p2剩下的内容连接到节点上.
                tail->next = p2;
            } else if(!p2) {
                tail->next = p1;
            }
        }
        if(flag == 1) {
            return l1;
        } else {
            return l2;
        }

    }
};

int main() {
    Solution s;


    ListNode node1(1);
    ListNode node2(1);

    ListNode node3(2);
    ListNode node4(3);

    node1.next = &node2;

    node3.next = &node4;

    ListNode * p = s.mergeTwoLists(&node1,&node3);

    while(p) {
        cout << p->val;
        p = p->next;
    }

}

