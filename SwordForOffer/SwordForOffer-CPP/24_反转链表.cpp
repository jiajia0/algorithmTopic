#include <iostream>
#include "./Utils/List.h"

using namespace std;

// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。



ListNode* ReverseList(ListNode* pHead) {
    ListNode* pReversedHead = nullptr;// 用来指向反转之后的头节点
    ListNode* pNode = pHead;// 指向当前节点
    ListNode* pPrev = nullptr;// 指向前一个节点

    while(pNode != nullptr) {
        ListNode* pNext = pNode->m_pNext;// 找到下一个节点

        if(pNext == nullptr)
            pReversedHead = pNode;

        pNode->m_pNext = pPrev;// 当前节点指向前一个节点
        pPrev = pNode;// 此时的节点是下一个节点的前节点
        pNode = pNext;// 当前节点向下一个移动
    }
    return pReversedHead;
}

// ====================测试代码====================
ListNode* Test(ListNode* pHead)
{
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode* pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// 输入的链表有多个结点
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入的链表只有一个结点
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入空链表
void Test3()
{
    Test(nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}
