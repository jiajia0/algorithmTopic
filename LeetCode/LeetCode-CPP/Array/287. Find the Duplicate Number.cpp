#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            int n = abs(nums[i]);
            if(nums[n] < 0) {
                return abs(nums[i]);
            } else {
                nums[n] *= -1;
            }
        }
        return -1;
    }
};*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];

        do {
            //cout << tortoise << "," << hare << endl;
            tortoise = nums[tortoise];//慢的走一步
            hare = nums[nums[hare]];//快的走两步
        } while(tortoise != hare);

        int ptr1 = nums[0];
        int ptr2 = tortoise;

        while(ptr1 != ptr2) {
            //cout << ptr1 << "," << ptr2 << endl;
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }

        return ptr1;
    }
};

int main() {
    Solution s;
    vector<int> num = {2,5,9,6,9,3,8,9,7,1};

    int ret = s.findDuplicate(num);
    cout << ret;
}



