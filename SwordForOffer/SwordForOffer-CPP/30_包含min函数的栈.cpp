#include <iostream>
using namespace std;

// 面试题30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min
// 函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。


#include <stack>
#include <assert.h>

template <typename T> class StackWithMin
{
public:
    StackWithMin() {}
    virtual ~StackWithMin() {}

    T& top();
    const T& top() const;

    void push(const T& value);
    void pop();

    const T& min() const;

    bool empty() const;
    size_t size() const;

private:
    std::stack<T>   m_data;     // 数据栈，存放栈的所有元素
    std::stack<T>   m_min;      // 辅助栈，存放栈的最小元素
};

// ------------------- 书中的做法
/*template <typename T> void StackWithMin<T>::push(const T& value)
{
    // 把新元素添加到辅助栈
    m_data.push(value);

    // 当新元素比之前的最小元素小时，把新元素插入辅助栈里；
    // 否则把之前的最小元素重复插入辅助栈里
    if(m_min.size() == 0 || value < m_min.top())
        m_min.push(value);
    else
        m_min.push(m_min.top());
}

template <typename T> void StackWithMin<T>::pop()
{
    assert(m_data.size() > 0 && m_min.size() > 0);

    m_data.pop();
    m_min.pop();
}*/

// 采用LeetCode中的思路，稍微有些不同，最下栈中不用保存太多元素
template <typename T> void StackWithMin<T>::push(const T& value)
{
    // 直接先将数据压入数据栈中
    m_data.push(value);
    // 如果此时最小栈是空的，则直接将该数值放入其中
    if(m_min.empty()) {
        m_min.push(value);
        return;
    }

    // 如果最小栈中不是空的，则判断最小栈的栈顶和当前数值
    // 如果当前数值比栈顶的还要小或者等于，则入栈
    if(value <= m_min.top())
        m_min.push(value);
}

template <typename T> void StackWithMin<T>::pop()
{
    assert(m_data.size() > 0 && m_min.size() > 0);

    // 如果数据栈和最小栈的栈顶相同，则说明此时是最小值，两个栈都出栈
    if(m_data.top() == m_min.top()) {
        m_data.pop();
        m_min.pop();
        return;
    }
    // 否则说明当前出栈的元素不是最小值，则只需要数据栈出栈即可
    m_data.pop();
}

template <typename T> const T& StackWithMin<T>::min() const
{
    assert(m_data.size() > 0 && m_min.size() > 0);

    return m_min.top();
}

template <typename T> T& StackWithMin<T>::top()
{
    return m_data.top();
}

template <typename T> const T& StackWithMin<T>::top() const
{
    return m_data.top();
}

template <typename T> bool StackWithMin<T>::empty() const
{
    return m_data.empty();
}

template <typename T> size_t StackWithMin<T>::size() const
{
    return m_data.size();
}





// 测试代码

void Test(const char* testName, const StackWithMin<int>& stack, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(stack.min() == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

int main(int argc, char* argv[])
{
    StackWithMin<int> stack;

    stack.push(3);
    Test("Test1", stack, 3);

    stack.push(4);
    Test("Test2", stack, 3);

    stack.push(2);
    Test("Test3", stack, 2);

    stack.push(3);
    Test("Test4", stack, 2);

    stack.pop();
    Test("Test5", stack, 2);

    stack.pop();
    Test("Test6", stack, 3);

    stack.pop();
    Test("Test7", stack, 3);

    stack.push(0);
    Test("Test8", stack, 0);

    return 0;
}
