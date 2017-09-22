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
    struct ListNode* getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
        if(!headA || !headB) {
            return NULL;
        }

        ListNode*a = headA;
        ListNode*b = headB;
        while(a!=b) {//相当于是交叉扫描一遍，如果有交点必然会相等
            a = a == NULL ? headB : a->next;
            b = b == NULL ? headA : b->next;
        }
        return a;
        //先遍历一个链表，再遍历另一个链表
        /*unordered_set<struct ListNode*> nodes;//用来存放
        while(headA) {
            nodes.insert(headA);
            headA = headA->next;
        }
        while(headB) {
            if(nodes.count(headB)) {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;*/

        //同时遍历两个链表
        /*while(headA && headB) {
            if(headA == headB) {
                //cout << "0. " << headA->val;
                return headA;
            }
            if(nodes.count(headA)) {//如果A节点在集合中能够找到，说明这是个交点
                //cout << "1. " << headA->val;
                return headA;
            } else if(nodes.count(headB)) {//B
                //cout << "2. " << headB->val;
                return headB;
            } else {
                nodes.insert(headA);
                nodes.insert(headB);
                headA = headA->next;
                headB = headB->next;
            }
        }
        if(!headA) {//如果A遍历完了，需要遍历一下B，因为可能B比A的长度长，A的最后一个节点可能B的中间一个，而此时B还没有遍历到
            while(headB) {
                if(nodes.count(headB)) {
                    //cout << "4. " << headB->val;
                    return headB;
                }
                headB = headB->next;
            }
        }
        if(!headB) {
            while(headA) {
                if(nodes.count(headA)) {
                    //cout << "5. " << headA->val;
                    return headA;
                }
                headA = headA->next;
            }
        }
        return NULL;*/
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

    node3.next = &node4;
    node4.next = &node5;


    node2.next = &node6;
    node5.next = &node6;

    ListNode * p = s.getIntersectionNode(&node1,&node3);
}

