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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> nodes;
        while(head) {
            if(nodes.count(head)==1) {
                return true;
            } else {
                nodes.insert(head);
            }
            head = head->next;
        }
        return false;
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

    s.hasCycle(&node1);


}

