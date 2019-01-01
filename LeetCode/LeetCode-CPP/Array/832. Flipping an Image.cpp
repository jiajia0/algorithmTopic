#include <iostream>
#include <vector>

using namespace std;

// Plan A
/*class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {

        if(A.size()==0 || A[0].size()==0)
            return A;

        int p1,p2;
        int i=0,j=0,temp;

        while(i < A.size()) {

            p1=0,p2=A[0].size()-1;// 分别从两端向中间进行扫描

            while(p1 <= p2) {
                temp = A[i][p1];// 记录下前面位置上的数字
                A[i][p1] = 1-A[i][p2];//如果对应后面位置为0，则将前面设置为1，否则设置为0
                A[i][p2] = 1-temp;//前面为0，后面设置为1，反之为0.
                p1++;
                p2--;
                if(p1 == p2) {//只剩下中间的一个数字
                    A[i][p1] = 1-A[i][p1];
                    break;
                }
            }
            i++;
        }
        return A;
    }
};*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); ++i){
            int begin = 0;
            int end = A[0].size()-1;
            while (begin < end){
                if(A[i][begin] == A[i][end]){// 如果前面和后面相等，此时需要进行对1进行异或，
                    A[i][begin] ^= 0X1;
                    A[i][end] ^= 0X1;
                }
                ++begin;
                --end;
            }
            if(begin == end) A[i][begin] ^=1;
        }
        return A;
    }
};

int main() {
    Solution s;
    vector<vector<int>> A = {{1,1,0,0},{1,0,0,1},{1,0,1,0}};
    vector<vector<int>> result = s.flipAndInvertImage(A);

    int i,j;
    for(i=0;i<result.size();i++) {
        for(j=0;j<result[0].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << endl ;
    }
    return 0;
}
