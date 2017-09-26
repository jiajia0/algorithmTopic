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
    ListNode *detectCycle(ListNode *head) {

        //快慢指针

        if(!head) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;

        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) {
                while(entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }

        }

        //赋值最大值法
        /*while(head) {
            if(head->val != INT_MAX) {
                head->val = INT_MAX;
            } else {
                return head;
            }
            head = head->next;
        }*/

        //集合的方法
        /*unordered_set<ListNode*> nodes;
        while(head) {
            if(nodes.count(head)==1) {
                return head;
            } else {
                nodes.insert(head);
            }
            head = head->next;
        }*/
        return nullptr;
    }
};

int main() {
    Solution s;


    ListNode node1(1);
    ListNode node2(1);

    ListNode node3(2);
    ListNode node4(3);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    s.detectCycle(&node1);


}

