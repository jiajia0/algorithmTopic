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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head) {
            return head;
        }

        ListNode* temp1,*temp2;
        temp1 = temp2 = head;

        int num = 0;
        while(num!=k) {//将temp1移动
            num++;
            if(!temp1->next) {//此时计算出链表的长度，并且更新k的值
                temp1 = head;
                k = k%num;//计算出余数
                num = 0;
            } else {
                temp1 = temp1->next;
            }
        }

        if(temp1 == temp2) {
            return temp1;
        } else {
            while(temp1->next) {//将temp2移动到需要断开的位置
                temp1 = temp1->next;
                temp2 = temp2->next;
            }

            ListNode* newHead = temp2->next;
            temp1->next = head;
            temp2->next = nullptr;

            return newHead;

        }

        /*int len = 1;
        ListNode* temp = head;
        while(temp->next) {//计算出总共有多少个节点
            temp = temp->next;
            len++;
        }

        temp->next = head;//将此时最后一个节点与第一个节点连接起来，然后可以直接从当前的节点进行遍历

        k = len - k;//计算出需要遍历多少个节点

        while(k%len) {//这里使用取模计算
            temp = temp->next;
            k--;
        }

        ListNode* newHead = temp->next;//新节点
        temp->next = NULL;//断开

        return newHead;*/

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
    //node3.next = &node4;
    //node4.next = &node5;
    //node5.next = &node6;

    ListNode* p = s.rotateRight(&node1,2000000000);
    while(p) {
        cout << p->val << ",";
        p = p->next;
    }

}

