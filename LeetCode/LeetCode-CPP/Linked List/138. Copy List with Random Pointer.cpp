/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return head;
        Node* iter = head,* next;
        // 把原来的链表复制一遍，每个节点出现两次
        while(iter != NULL) {
            next = iter->next; // 记录下一个节点
            Node* node = new Node(iter->val, NULL, NULL);
            iter->next = node;
            node->next = next;
            iter = next;
        }
        // 从头开始，连接上random指针
        iter = head;
        while(iter != NULL) {
            if(iter->random != NULL) {
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        // 把原来的链表分割出来，并且不能修改原来的链表的指针
        iter = head;
        Node* copy = iter->next;
        Node* copyHead = copy;
        while(copy->next != NULL) {
            iter->next = iter->next->next;
            iter = iter->next;
            
            copy->next = copy->next->next;
            copy = copy->next;
        }
        iter->next = NULL; // 最后一个赋值为NULL，或者iter->next = iter->next->next;
        return copyHead;
    }
};