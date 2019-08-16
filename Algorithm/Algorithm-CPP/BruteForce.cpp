#include <iostream>

using namespace std;

// 匹配到返回index，匹配不到返回-1 , 假设不为空
int BruteForce(string str, string p) {
    int i = 0;// i 用来记录str比较的位置
    int j = 0;// j 用来记录p比较的位置
    while(i < str.size() && j < p.size()) {
        if(str[i] == p[j]) { // 若当前字符相等，则向后比较
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if(j == p.size()) {
        return i - j;
    }
    return -1;
}

int main() {
    string str = "here is a example";
    string p = "hera";
    int ans = BruteForce(str, p);
    cout << ans;
    return 0;
}
