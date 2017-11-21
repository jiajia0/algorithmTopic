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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || m==n) {
            return head;
        }

        ListNode* dummpy = new ListNode(0);
        dummpy->next = head;
        ListNode* temp = dummpy;
        ListNode* result = new ListNode(0);
        ListNode* tail = result;

        stack<ListNode*> node1;
        stack<ListNode*> node2;

        int num = n - m + 1;//需要加1,此时需要包含后面的那个节点

        m--;
        while(m) {//将m之前的都存放在node1栈中
            temp = temp->next;
            node1.push(temp);
            m--;
        }

        while(num&&temp) {
            temp = temp->next;
            node2.push(temp);
            num--;
        }

        if(temp) {
            temp = temp->next;//移动到变换后的一个节点
        }

        while(!node1.empty()) {//前面的顺序不变，所以使用头插法
            node1.top()->next = result->next;
            result->next = node1.top();
            if(tail == result) {
                tail = node1.top();
            }
            node1.pop();
        }


        while(!node2.empty()) {
            tail->next = node2.top();
            tail = tail->next;
            node2.pop();
        }

        while(temp) {
            tail->next = temp;
            tail = temp;
            temp = temp->next;
        }

        tail->next = nullptr;

        return result->next;


        /*ListNode* dummpy = new ListNode(0);
        dummpy->next = head;
        ListNode* start = dummpy;//指向需要变换的开头
        ListNode* tail = nullptr;//指向需要变换的结尾
        ListNode* temp = nullptr;
        ListNode* p1,*p2;

        int num = n - m;

        m--;

        while(m) {//运行到需要变换位置的前一个节点
            start = start->next;
            m--;
        }

        p1 = start;//记录中断的位置
        p2 = start->next;//记录转换后的最后一个位置

        start = start->next;//此刻的位置才是需要开始变换的位置
        temp = start->next;//指向下一个节点
        start->next = nullptr;

        while(temp && num) {
            tail = temp->next;
            temp->next = start;

            start = temp;
            temp = tail;
            num--;
        }


        p1->next = start;


        while(temp) {//需要用temp而不是tail，因为tail可能为空
            p2->next = temp;
            p2 = temp;
            temp = temp->next;
        }

        return dummpy->next;*/
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
    //node3.next = &node4;
    //node4.next = &node5;

    ListNode* p = s.reverseBetween(&node1,2,3);

    while(p) {
        cout << p->val;
        cout << endl;
        p = p->next;
    }

}

