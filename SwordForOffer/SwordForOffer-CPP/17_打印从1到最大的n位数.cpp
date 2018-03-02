#include <iostream>
#include <string.h>

using namespace std;

// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。

bool Increment(char* number);
void PrintNumber(char* number);
void Print1ToMaxOfNDigitsRecursively(char* number,int length,int index);

void Print1ToMaxOfNDigits_1(int n) {
    if(n <= 0)
        return;

    char* number = new char[n+1];
    memset(number,'0',n);
    number[n] = '\0';

    while(!Increment(number)) {
        PrintNumber(number);
    }
    delete[] number;
}

// 用来对数字自增
bool Increment(char* number) {
    bool isOverflow = false;// 用来标记是否结束
    int nTakeOver = 0;// 进位的时候使用，值只有0和1
    int nLength = strlen(number);

    for(int i=nLength-1;i>=0;i--) {

        int nSum = number[i] - '0' + nTakeOver;
        // 如果此时是最小位
        if(i == nLength-1)
            nSum++;
        if(nSum >= 10) {// 如果大于10则进位，并且判断是否已经最大
            if(i == 0)// 此刻已经是最大了，所以结束
                isOverflow = true;
            else {// 进行进位
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        } else {// 如果小于10，则直接相加
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverflow;
}

// 用来打印数字
void PrintNumber(char* number) {
    // 用来标记是不是0
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for(int i=0; i < nLength; i++) {
        // 如果前面的都是0，而此刻不是0
        if(isBeginning0 && number[i]!='0')
            isBeginning0 = false;
        // 如果开头不为0，则打印结果
        if(!isBeginning0)
            printf("%c",number[i]);
    }
    printf("\t");
}

// 全排列
void Print1ToMaxOfNDigits_2(int n) {
    if(n <= 0)
        return;
    char* number = new char[n + 1];
    number[n] = '\0';

    for(int i=0; i < 10; i++) {
        number[0] = i+'0';
        Print1ToMaxOfNDigitsRecursively(number,n,0);
    }

    delete[] number;
}
// 利用递归，依次输出001、002、003...099
void Print1ToMaxOfNDigitsRecursively(char* number,int length,int index) {
    if(index == length - 1) {
        PrintNumber(number);
        return;
    }
    for(int i=0; i<10; i++) {
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number,length,index+1);
    }
}

// ====================测试代码====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);

    Print1ToMaxOfNDigits_1(n);
    Print1ToMaxOfNDigits_2(n);
    printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(0);
    Test(-1);

    return 0;
}
