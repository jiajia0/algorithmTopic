#include <iostream>

using namespace std;

// 利用辅助空间求解
int getDuplication(const int* numbers, int length) {
    if(numbers == nullptr || length <= 0) {
        return -1;
    }

    int other[length] = {0};


    for(int i=0;i < length;i++) {
        if(other[numbers[i]-1] == 0) {
            other[numbers[i]-1] = numbers[i];
        } else {
            //cout << "find:" << numbers[i];
            return numbers[i];
        }
        if(i == length-1) {
            return -1;
        }
    }
    return -1;
}


/*
// 统计在范围内共有多少数字
int countRange(const int* numbers,int length,int start,int end) {
    if (numbers == nullptr)
        return 0;
    int count =0;
    for(int i=0; i<length; i++) {
        if(numbers[i] >= start && numbers[i] <= end) {
            count++;
        }
    }
    return count;
}


// 书中解法
int getDuplication(const int* numbers, int length) {

    if(numbers == nullptr || length <= 0) {
        return -1;
    }

    int start = 1;
    int end = length - 1;

    while(end >= start) {
        // 求出中间的数字
        int middle = ((end-start) >> 1) + start;
        // 统计出在start和middle中共有多少个数字
        int count = countRange(numbers,length,start,middle);
        // 如果此时开始位置和结束位置一样
        if(end == start) {
            // 统计的数字大于说明重复了
            if(count > 1) {
                return start;
            } else {
                break;
            }
        }

        if(count > (middle - start + 1))
            end = middle;
        else
            start = middle + 1;
    }
    return -1;
}*/

// LeetCode 解法，不能处理没有重复的情况
/*int getDuplication(const int* numbers, int length) {
    if(numbers == nullptr || length <= 0) {
        return false;
    }

    int tortoise = numbers[0];
    int hare = numbers[0];

    do {
        tortoise = numbers[tortoise];
        hare = numbers[numbers[hare]];
    } while(tortoise != hare);


    int ptr1 = numbers[0];
    int ptr2 = tortoise;

    while(ptr1 != ptr2) {
        ptr1 = numbers[ptr1];
        ptr2 = numbers[ptr2];
    }

    return ptr1;
}*/


// ====================测试代码====================
void test(const char* testName, int* numbers, int length, int* duplications, int dupLength)
{
    int result = getDuplication(numbers, length);
    for(int i = 0; i < dupLength; ++i)
    {
        if(result == duplications[i])
        {
            std::cout << testName << " passed." << std::endl;
            return;
        }
    }
    std::cout << testName << " FAILED." << std::endl;
}

// 多个重复的数字
void test1()
{
    int numbers[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
    int duplications[] = { 2, 3 };
    test("test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 一个重复的数字
void test2()
{
    int numbers[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
    int duplications[] = { 4 };
    test("test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 重复的数字是数组中最小的数字
void test3()
{
    int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
    int duplications[] = { 1 };
    test("test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 重复的数字是数组中最大的数字
void test4()
{
    int numbers[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
    int duplications[] = { 8 };
    test("test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 数组中只有两个数字
void test5()
{
    int numbers[] = { 1, 1 };
    int duplications[] = { 1 };
    test("test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 重复的数字位于数组当中
void test6()
{
    int numbers[] = { 3, 2, 1, 3, 4, 5, 6, 7 };
    int duplications[] = { 3 };
    test("test6", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 多个重复的数字
void test7()
{
    int numbers[] = { 1, 2, 2, 6, 4, 5, 6 };
    int duplications[] = { 2, 6 };
    test("test7", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 一个数字重复三次
void test8()
{
    int numbers[] = { 1, 2, 2, 6, 4, 5, 2 };
    int duplications[] = { 2 };
    test("test8", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 没有重复的数字
void test9()
{
    int numbers[] = { 1, 2, 6, 4, 5, 3 };
    int duplications[] = { -1 };
    test("test9", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 无效的输入
void test10()
{
    int* numbers = nullptr;
    int duplications[] = { -1 };
    test("test10", numbers, 0, duplications, sizeof(duplications) / sizeof(int));
}

int  main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    return 1;
}
