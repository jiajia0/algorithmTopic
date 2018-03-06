#include <iostream>
using namespace std;

// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
// 字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
// “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是

// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，其中A和C都是
// 整数（可以有正负号，也可以没有），而B是一个无符号整数

bool scanUnsignedInteger(const char** str) {
    const char* before = *str;// 记录下此时的位置
    while(**str!='\0' && **str>='0' && **str<='9')// 如果存在0到9，则向后移动
        (*str)++;
    return *str > before;// 如果大于则说明存在0到9的数字
}

// 用来判断是否表示正负
bool scanInterger(const char** str) {
    if(**str == '+' || **str == '-')// 如果此时开头部分是+或者-，则向后移动一位越过符号
        (*str)++;
    return scanUnsignedInteger(str);
}

bool isNumeric(const char* str) {
    if(str == nullptr)
        return false;
    // 扫描正负号，以及数字
    bool numeric = scanInterger(&str);

    // 出现小数点，后面的部分就是小数部分了
    if(*str == '.') {
        str++;
        // 这里使用的是'或'，并不是'并'，
        // 因为上面的numeric计算出小数点前面的部分了，
        // 1. 小数可以没有整数部分，比如：.123 == 0.123 ，此时||之前的计算是true，||之后计算的是false
        // 2. 小数点后面可以没有数字，比如：233. == 233.0 , 此时||之前的为false，||之后计算的是true。
        // 3. 小数点前后都有数字，此时||前后都是true。
        numeric = scanUnsignedInteger(&str) || numeric;
    }
    // 出现'e'或者'E'，后面的就是指数部分了
    if(*str == 'e' || *str == 'E') {
        str++;
        // 此时必须用&& ，因为e前后都必须要有整数才行
        numeric = numeric && scanInterger(&str);
    }
    return numeric && *str=='\0';// 此时应该是结束的了
}

// ====================测试代码====================
void Test(const char* testName, const char* str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(isNumeric(str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}


int main(int argc, char* argv[])
{
    Test("Test1", "100", true);
    Test("Test2", "123.45e+6", true);
    Test("Test3", "+500", true);
    Test("Test4", "5e2", true);
    Test("Test5", "3.1416", true);
    Test("Test6", "600.", true);
    Test("Test7", "-.123", true);
    Test("Test8", "-1E-16", true);
    Test("Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    Test("Test10", "12e", false);
    Test("Test11", "1a3.14", false);
    Test("Test12", "1+23", false);
    Test("Test13", "1.2.3", false);
    Test("Test14", "+-5", false);
    Test("Test15", "12e+5.4", false);
    Test("Test16", ".", false);
    Test("Test17", ".e1", false);
    Test("Test18", "e1", false);
    Test("Test19", "+.", false);
    Test("Test20", "", false);
    Test("Test21", nullptr, false);

    return 0;
}
