#include <iostream>

using namespace std;

//在一个长度为n的数组里的所有数字都在0~n-1的范围内。
//数组中某些数字是重复的，但不知道有几个数字重复了，
//也不知道每个数字重复了几次，请找出数组中任意一个重复的数字.

bool duplicate(int numbers[], int length, int* duplication) {
    // 检测
    if(numbers == nullptr || length <= 0) {
        return false;
    }
    // 检测数组内容是否有效
    for(int i=0; i < length; i++) {
        if(numbers[i] < 0 || numbers[i] > length-1 ) {
            return false;
        }
    }

    // LeetCode解法
    for(int i=0; i<length; i++) {
        int temp = abs(numbers[i]);
        if(numbers[temp] < 0) {
            *duplication = -numbers[temp];
            return true;
        }
        numbers[temp] = -numbers[temp];
    }

    // 书中解法
    /*// 遍历数组
    for(int i=0; i<length; i++) {
        // 当前下表与数组元素不相等
        while(numbers[i] != i) {
            // 如果当前元素与以当前元素为下标的位置上发元素相等，则说明重复
            if(numbers[i] == numbers[numbers[i]]) {
                *duplication = numbers[i];
                return true;
            }

            // 交换Numbers[i] 和 numbser[numbser[i]]
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;

        }
    }*/

    return false;
}

// ====================测试代码====================
bool contains(int array[], int length, int number)
{
    for(int i = 0; i < length; ++i)
    {
        if(array[i] == number)
            return true;
    }

    return false;
}

void test(char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
    printf("%s begins: ", testName);

    int duplication;
    bool validInput = duplicate(numbers, lengthNumbers, &duplication);

    if(validArgument == validInput)
    {
        if(validArgument)
        {
            if(contains(expected, expectedExpected, duplication))
                printf("Passed.\n");
            else
                printf("FAILED.\n");
        }
        else
            printf("Passed.\n");
    }
    else
        printf("FAILED.\n");
}

// 重复的数字是数组中最小的数字
void test1()
{
    int numbers[] = { 2, 1, 3, 1, 4 };
    int duplications[] = { 1 };
    test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 重复的数字是数组中最大的数字
void test2()
{
    int numbers[] = { 2, 4, 3, 1, 4 };
    int duplications[] = { 4 };
    test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 数组中存在多个重复的数字
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplications[] = { 2, 4 };
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 没有重复的数字
void test5()
{
    int numbers[] = { 2, 1, 3, 5, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test6()
{
    int* numbers = nullptr;
    int duplications[] = { -1 }; // not in use in the test function
    test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 1;
}
