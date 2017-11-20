#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> nodes;
        int counts = 0;//用来统计链表共有多少个节点
        ListNode* p = root;

        while(p) {//循环计算出总共的节点数
            p = p->next;
            counts++;
        }

        int num,rem,i,j;
        num = counts/k;//计算出每节有多少个固定节点
        rem = counts%k;//计算出余数，也就是前多少个段需要多一个节点

        for(i=0;i<k;i++) {
            ListNode* head = new ListNode(0);//新建一个新的头结点
            p = head;
            for(j=0;j<num;j++) {//每个节点的固定个数进行添加
                ListNode* node = new ListNode(root->val);
                p->next = node;
                p = p->next;
                if(root) {
                    root = root->next;
                }
            }
            if(rem-- > 0 && root) {//需要多加一个节点
                ListNode* rmnode = new ListNode(root->val);
                p->next = rmnode;
                if(root) {
                    root = root->next;
                }
            }

            nodes.push_back(head->next);//添加到数组中
        }

        return nodes;

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

    vector<ListNode*> node = s.splitListToParts(&node1,5);
    int i = 0;
    for(i=0;i<node.size();i++) {
        ListNode* p = node[i];
        while(p) {
            cout << p->val << endl;
            p = p->next;
        }
        cout << endl;
    }
}

