#include <iostream>
#include <vector>

using namespace std;

/*class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result(n);//构造一个n个元素的数组
        int num=0;//数组的下标

        //构造前半部分，只会产生1种结果
        for(int i=1; i < n-k; i++) {
            result[num++] = i;
        }

        //构造后半部分，能够产生k-1种结果
        for(int i=0; i <= k; i++) {
            //如果是下标为偶数就取第一个数，奇数取最后一个数
            result[num++] = (i%2 == 0) ? (n-k + i/2) : (n - i/2);
        }

        return result;

    }
};*/

class Solution{
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int i = 1, j = n;
        while (i <= j) {
            if (k > 1) res.push_back(k-- % 2 ? i++ : j--);
            else res.push_back(i++);
        }
        return res;
    }
};


int main() {
    Solution s;

    vector<int> n = s.constructArray(6,5);
    int i;
    for(i=0;i<n.size();i++) {//将所有的数字放到一个数组中
        std::cout << n[i] << std::endl;
    }
    return 0;
}

