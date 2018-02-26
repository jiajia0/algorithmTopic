#include <iostream>
using namespace std;

// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。


int NumberOf1_Solution1(int n) {
    int count = 0;
    unsigned int flag = 1;
    while(flag) {
        if(n&flag)
            count++;
        flag= flag << 1;// 左移一位，不是数字左移，而是flag左移
    }
    return count;
}
// 数字减去一之后，相当于把左右边的1变为0，
// 并且左右边的1的右边变为0，如1100 减去一：1011，
// 减去一的数字与原来的数字于运算，则相当于把最右边一个1变为0
int NumberOf1_Solution2(int n) {
    int count = 0;
    while(n) {
        count++;
        n = (n-1)&n;
    }
    return count;
}

// ====================测试代码====================
void Test(int number, unsigned int expected)
{
    int actual = NumberOf1_Solution1(number);
    if (actual == expected)
        printf("Solution1: Test for %p passed.\n", number);
    else
        printf("Solution1: Test for %p failed.\n", number);

    actual = NumberOf1_Solution2(number);
    if (actual == expected)
        printf("Solution2: Test for %p passed.\n", number);
    else
        printf("Solution2: Test for %p failed.\n", number);

    printf("\n");
}

int main(int argc, char* argv[])
{
    // 输入0，期待的输出是0
    Test(0, 0);

    // 输入1，期待的输出是1
    Test(1, 1);

    // 输入10，期待的输出是2
    Test(10, 2);

    // 输入0x7FFFFFFF，期待的输出是31
    Test(0x7FFFFFFF, 31);

    // 输入0xFFFFFFFF（负数），期待的输出是32
    Test(0xFFFFFFFF, 32);

    // 输入0x80000000（负数），期待的输出是1
    Test(0x80000000, 1);

    return 0;
}
