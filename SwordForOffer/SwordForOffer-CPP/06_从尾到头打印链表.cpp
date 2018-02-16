#include <iostream>
#include <stack>
#include "./Utils/List.h"


using namespace std;

// 利用栈
void PrintListReversingly_Iteratively(ListNode* pHead) {
    std::stack<ListNode*> nodes;

    ListNode* pNode = pHead;
    while(pNode != nullptr) {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while(!nodes.empty()) {
        pNode = nodes.top();
        cout << pNode->m_nValue << "\t";
        nodes.pop();
    }
}

// 递归处理，输出当前节点时先输出后一个节点
void PrintListReversingly_Recursively(ListNode* pHead) {
    if(pHead != nullptr) {
        if(pHead->m_pNext != nullptr) {
            PrintListReversingly_Recursively(pHead->m_pNext);
        }
        cout << pHead->m_nValue << "\t";
    }
}

// ====================测试代码====================
void Test(ListNode* pHead)
{
    PrintList(pHead);
    PrintListReversingly_Iteratively(pHead);
    printf("\n");
    PrintListReversingly_Recursively(pHead);
}

// 1->2->3->4->5
void Test1()
{
    printf("\nTest1 begins.\n");

    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1);

    DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void Test2()
{
    printf("\nTest2 begins.\n");

    ListNode* pNode1 = CreateListNode(1);

    Test(pNode1);

    DestroyList(pNode1);
}

// 空链表
void Test3()
{
    printf("\nTest3 begins.\n");

    Test(nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}
