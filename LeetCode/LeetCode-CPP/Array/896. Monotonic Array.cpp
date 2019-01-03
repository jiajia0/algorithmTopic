#include <iostream>
#include <vector>

using namespace std;

/*class Solution {
public:
    bool isMonotonic(vector<int>& A) {

        if(A.size() == 1)
            return true;

        int i=1;
        bool increase=false;
        bool decrease=false;
        while(i<A.size()) {
            if(A[i] == A[i-1]) {
                i++;
                continue;
            }

            if(A[i] > A[i-1]){//递增
                if(increase==false&&decrease==true)
                    return false;
                increase = true;
                decrease = false;
            }else {
                if(decrease==false&&increase==true)
                    return false;
                decrease = true;
                increase = false;
            }
            i++;
        }
        return true;
    }
};*/

class Solution {
public:
    bool isMonotonic(vector<int>& A) {

        int sign = 0;//记录上次的变化
        int n = A.size();
        for (int i = 0; i < n - 1; i++) {
            int new_sign;
            if (A[i+1] > A[i])
                new_sign = 1;
            else if (A[i+1] < A[i])
                new_sign = -1;
            else
                new_sign = 0;

            if (new_sign != 0 && new_sign == -sign)//如果发生了变化，并且与之前的变化相反则返回false
                return false;

            if (sign == 0)//如果上一次代表着不变，则更新为这一次的变化
                sign = new_sign;
        }
        return true;
    }

};

int main() {
    Solution s;
    vector<int> A = {1,1,0};
    bool ret = s.isMonotonic(A);
    cout << ret;
    return 0;
}
