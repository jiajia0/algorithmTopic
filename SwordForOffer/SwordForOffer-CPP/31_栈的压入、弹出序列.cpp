#include <iostream>
#include <stack>

using namespace std;

// 面试题31：栈的压入、弹出序列
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
// 否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、
// 5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
// 4、3、5、1、2就不可能是该压栈序列的弹出序列。

bool IsPopOrder(const int* pPush,const int* pPop,int nLength) {
    bool bPossible = false;// 标记结果

    // 如果不为空的话才继续执行
    if(pPush != nullptr && pPop != nullptr && nLength) {
        const int* pNextPush = pPush;// 用来标记下一个需要压栈的元素的指针
        const int* pNextPop = pPop;// 用来标记下一个需要出栈的元素的指针

        stack<int> stackData;// 辅助栈

        // 如果遍历的长度小于栈的长度，就继续执行
        while(pNextPop-pPop < nLength) {
            // 如果辅助栈是空的，或者辅助栈顶元素不等于希望出栈的元素，就继续压栈，直到遇到了希望出栈的元素
            while(stackData.empty() || stackData.top()!=*pNextPop) {
                // 说明入栈序列已经遍历完了
                if(pNextPush-pPush == nLength)
                    break;
                // 将入栈序列的下一个元素入栈
                stackData.push(*pNextPush);
                pNextPush++;
            }
            // 如果已经找完了，此刻还是不等于，则说明失败了
            if(stackData.top() != *pNextPop)
                break;
            // 将希望出栈的元素出栈
            stackData.pop();
            pNextPop++;
        }

        // 如果辅助栈为空，并且此时遍历的长度正好等于序列的长度，说明就是一个出栈序列
        if(stackData.empty()&&pNextPop-pPop==nLength)
            bPossible = true;
    }

    return bPossible;
}


// ====================测试代码====================
void Test(const char* testName, const int* pPush, const int* pPop, int nLength, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(IsPopOrder(pPush, pPop, nLength) == expected)
        printf("Passed.\n");
    else
        printf("failed.\n");
}

void Test1()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 5, 3, 2, 1};

    Test("Test1", push, pop, nLength, true);
}

void Test2()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 2, 1};

    Test("Test2", push, pop, nLength, true);
}

void Test3()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 3, 5, 1, 2};

    Test("Test3", push, pop, nLength, false);
}

void Test4()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 1, 2};

    Test("Test4", push, pop, nLength, false);
}

// push和pop序列只有一个数字
void Test5()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {2};

    Test("Test5", push, pop, nLength, false);
}

void Test6()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {1};

    Test("Test6", push, pop, nLength, true);
}

void Test7()
{
    Test("Test7", nullptr, nullptr, 0, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
