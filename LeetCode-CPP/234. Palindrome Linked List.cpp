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
    bool isPalindrome(ListNode* head) {
        stack<int> halfValues;//使用一个栈来保存链表前半边的节点.
        ListNode* fast = head;
        ListNode* slow = head;
        if(!head) {
            return true;
        }
        while(fast&&fast->next) {//使用快慢指针找到链表中点
            fast = fast->next->next;
            halfValues.push(slow->val);
            slow = slow->next;
        }
        if(fast) {//fast指向不为空说明为奇数,此时不需要比较最中间的那个数值
            slow = slow->next;
        }

        while(slow) {//不为空则遍历
            if(slow->val != halfValues.top()) {
                return false;
            } else {
                halfValues.pop();
                slow = slow->next;
            }
        }
        return true;

    }
};
int main() {
    Solution s;


    ListNode node1(1);
    ListNode node2(2);

    ListNode node3(2);
    ListNode node4(1);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    cout << s.isPalindrome(&node1);


}

