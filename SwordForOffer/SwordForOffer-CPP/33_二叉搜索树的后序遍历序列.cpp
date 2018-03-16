#include <iostream>
using namespace std;

// 面试题33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。

bool VerifySquenceOfBST(int sequence[], int length) {
    if(sequence == nullptr || length < 0)
        return false;

    int root = sequence[length - 1];// 获取到根节点

    int i = 0;
    // 此时在序列中找出比根节点小的部分，这部分就是二叉搜索树根节点的左节点
    for(;i<length-1;i++) {
        // 当发现数值比根节点大的时候就结束
        if(sequence[i] > root)
            break;
    }

    int j = i;
    // 剩下的部分应该是根节点的右节点，应该全部比根节点大
    for(;j<length-1;j++) {
        // 如果发现比根节点小的则说明错误了
        if(sequence[j] < root)
            return false;
    }

    // 标记跟节点的左子树是不是二叉搜索树
    bool left = true;
    // i大于零代表存在左子树
    if(i > 0)
        left = VerifySquenceOfBST(sequence,i);

    // 标记跟节点的右子树是不是二叉搜索树
    bool right = true;
    // 说明存在右子树
    if(i < length - 1)
        right = VerifySquenceOfBST(sequence+i,length-i-1);
    return (left&&right);
}

// ====================测试代码====================
void Test(const char* testName, int sequence[], int length, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(VerifySquenceOfBST(sequence, length) == expected)
        printf("passed.\n");
    else
        printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    int data[] = {4, 8, 6, 12, 16, 14, 10};
    Test("Test1", data, sizeof(data)/sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2()
{
    int data[] = {4, 6, 7, 5};
    Test("Test2", data, sizeof(data)/sizeof(int), true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test3()
{
    int data[] = {1, 2, 3, 4, 5};
    Test("Test3", data, sizeof(data)/sizeof(int), true);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test4()
{
    int data[] = {5, 4, 3, 2, 1};
    Test("Test4", data, sizeof(data)/sizeof(int), true);
}

// 树中只有1个结点
void Test5()
{
    int data[] = {5};
    Test("Test5", data, sizeof(data)/sizeof(int), true);
}

void Test6()
{
    int data[] = {7, 4, 6, 5};
    Test("Test6", data, sizeof(data)/sizeof(int), false);
}

void Test7()
{
    int data[] = {4, 6, 12, 8, 16, 14, 10};
    Test("Test7", data, sizeof(data)/sizeof(int), false);
}

void Test8()
{
    Test("Test8", nullptr, 0, false);
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
    Test8();

    return 0;
}
