#include <iostream>
using namespace std;

// 面试题29：顺时针打印矩阵
// 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

void printNumber(int number)
{
    printf("%d\t", number);
}

void PrintMatrixInCircle(int** numbers,int columns,int rows,int start) {
    // 计算出终止列号和行号
    int endX = columns - 1 - start;
    int endY = rows - 1 - start;

    // 从左到右打印
    for(int i=start; i<= endX; i++) {
        int number = numbers[start][i];
        printNumber(number);
    }

    // 如果此时开始行小于终止的行，才进行打印
    if(start < endY) {
        // 注意此时的开始位置需要在start上加一，因为第一个数字在上面从左到右打印的时候已经打印了
        for(int i=start+1;i<=endY;i++) {
            int number = numbers[i][endX];// 这里需要使用endX
            printNumber(number);
        }
    }

    // 行数和列数都不至一个的时候，从右往左打印
    if(start < endX && start < endY) {
        for(int i=endX-1; i>= start;i--) {
            int number = numbers[endY][i];
            printNumber(number);
        }
    }

    // 不止一列，并且行数大于两行，因为如果等于两行的从左到右和从右到左已经打印完了
    if(start < endX && start < endY-1) {
        for(int i=endY-1; i >= start+1; i--) {
            int number = numbers[i][start];
            printNumber(number);
        }
    }

}

void PrintMatrixClockwisely(int** numbers,int columns,int rows) {
    if(numbers == nullptr || columns <= 0 || rows <= 0)
        return;
    int start = 0;

    while(columns > start*2 && rows > start*2) {
        PrintMatrixInCircle(numbers,columns,rows,start);
        start++;
    }
}

// ====================测试代码====================
void Test(int columns, int rows)
{
    printf("Test Begin: %d columns, %d rows.\n", columns, rows);

    if(columns < 1 || rows < 1)
        return;

    int** numbers = new int*[rows];
    for(int i = 0; i < rows; ++i)
    {
        numbers[i] = new int[columns];
        for(int j = 0; j < columns; ++j)
        {
            numbers[i][j] = i * columns + j + 1;
        }
    }

    PrintMatrixClockwisely(numbers, columns, rows);
    printf("\n");

    for(int i = 0; i < rows; ++i)
        delete[] (int*)numbers[i];

    delete[] numbers;
}

int main(int argc, char* argv[])
{
    /*
    1
    */
    Test(1, 1);

    /*
    1    2
    3    4
    */
    Test(2, 2);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
    Test(4, 4);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    21   22   23   24   25
    */
    Test(5, 5);

    /*
    1
    2
    3
    4
    5
    */
    Test(1, 5);

    /*
    1    2
    3    4
    5    6
    7    8
    9    10
    */
    Test(2, 5);

    /*
    1    2    3
    4    5    6
    7    8    9
    10   11   12
    13   14   15
    */
    Test(3, 5);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    17   18   19   20
    */
    Test(4, 5);

    /*
    1    2    3    4    5
    */
    Test(5, 1);

    /*
    1    2    3    4    5
    6    7    8    9    10
    */
    Test(5, 2);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14    15
    */
    Test(5, 3);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    */
    Test(5, 4);

    return 0;
}
