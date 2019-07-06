#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int result = A[0];
        map<int,int> nums;
        for(int i : A) { // 把元素放到map中
            nums[i]++;
            if(nums[i] == A.size()/2)
                return i;
        }

        /*map<int,int>::iterator it = nums.begin();
        int max = 0;
        while(it != nums.end()) { // 遍历map找到value最大的数值，以及对应的元素
            if(it->second > max) {
                max = it->second;
                result = it->first;
            }
            it++;
        }*/

        return result;
    }
};


/*class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int result = A[0];
        //
        for(int i : A) {
            if(count(A.begin(),A.end(),i) == A.size()/2) // 统计当前元素的个数，如果等于N，则直接返回
                return i;
        }
        return result;
    }
};*/

int main() {
    Solution s;
    vector<int> nums = {5,1,5,2,5,3,5,4};
    int result = s.repeatedNTimes(nums);
    cout << result << endl;
    return 0;
}
