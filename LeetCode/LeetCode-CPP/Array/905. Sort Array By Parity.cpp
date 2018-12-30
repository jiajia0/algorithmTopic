#include <iostream>
#include <vector>

using namespace std;

// plan A
/*class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i=0,j=0,num_len = A.size();
        vector<int> even_vector,odd_vector;
        while(i < num_len) {
            if(A[i]%2 == 0)//even
                even_vector.push_back(A[i]);
            else//odd
                odd_vector.push_back(A[i]);
            i++;
        }
        i=0,j=0;
        while(i < even_vector.size()) {
            A[i] = even_vector[j];
            i++;
            j++;
        }
        j=0;
        while(j < odd_vector.size()) {
            A[i] = odd_vector[j];
            i++;
            j++;
        }
        return A;
    }
};*/

// plan B
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> result(A.size(),0);// 定义一个与A一样大的容器
        int even_index=0;
        int odd_index = A.size() - 1;
        int i=0;
        while(even_index <= odd_index) {
            if(A[i]%2 == 0)// even
                result[even_index++] = A[i];
            else // odd
                result[odd_index--] = A[i];
            i++;
        }
        return result;
    }
};


// plan C
/*class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int even_index = 0;// 偶数的索引，从前往后
        int odd_index = A.size()-1;// 奇数的索引，从后往前
        while(even_index < odd_index) {
            while(A[even_index]%2==0) even_index++;// 如果当前是偶数，则向后寻找
            while(A[odd_index]%2!=0) odd_index--;// 如果当前是奇数，则向前寻找

            if(even_index < odd_index)
                swap(A[even_index],A[odd_index]);
        }
        return A;
    }
};*/



int main() {
    Solution s;
    vector<int> nums = {3,1,2,4};

    vector<int> result = s.sortArrayByParity(nums);
    for(int num : result)
        cout << num;
    return 0;
}



