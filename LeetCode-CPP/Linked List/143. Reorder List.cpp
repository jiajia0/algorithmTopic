#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) {
            return;
        }

        ListNode *p1 = head;
        ListNode *p2 = head->next;

        //利用快慢指针的性质将链表平均分开，偶数的话平均分，奇数的话第一节比第二节多一个
        while(p2&&p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        ListNode* head2  = p1->next;//p1指向第一节的最后一个节点，所以下一个就是第二节的开始
        ListNode* temp;
        p1->next = NULL;//彻底断开

        p2 = head2->next;//指向head2的下一个节点

        head2->next = NULL;//将此时head2孤立开，为了做第二节反向后的最后一个节点

        while(p2) {
            temp = p2->next;//先用temp记录下p2的下一个节点
            p2->next = head2;//反向链接
            head2 = p2;
            p2 = temp;
        }

        /*while(head) {
            cout << head->val << ",";
            head = head->next;
        }

        cout << endl;

        while(head2) {
            cout << head2->val << ",";
            head2 = head2->next;
        }*/

        //将两节链表融合起来
        p1 = head;
        p2 = head2;

        //交叉链接起来
        while(p2) {//要么两节相等，要么第一节多，所以这里用第二节做为判断空的条件
            temp = p1->next;
            p1->next = p2;
            p1 = p2;
            p2 = temp;
        }

        /*while(head) {
            cout << head->val << ",";
            head = head->next;
        }*/

    }
};

int main() {
    Solution s;

    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    ListNode node6(6);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;

    s.reorderList(&node1);

}

