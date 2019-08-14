#include <iostream>
#include <vector>

using namespace std;


/* 模板 
int start = 0, end = nums.length - 1;
while (start + 1 < end) { // 保证start和end都为有效值，若写为start<=end ，则可能end为-1
    int mid = start + (end - start) / 2;  // 防止越界，eg：end = 2^32-1,start = 100 ， 若使用(start + end) / 2 则会越界

    if (...) {
        start = mid;
    } else {
        end = mid;
    }
}
*/

// 二分查找，找到target所在的index，没有找到返回-1 ， 若有相同的则返回最后一个的index
int BinarySearch(vector<int> nums, int target) {
    int start = 0, end = nums.size() - 1;
    while(start + 1 < end) {
        int mid = start + (end - start) / 2;
        if(nums[mid] <= target) {
            start = mid;
        } else {
            end = mid;
        }
    }
    if(nums[start] == target)
        return start;
    if(nums[end] == target)
        return end;

    return -1;
}

int main() {
    vector<int> nums = {1,2,2,3,3,4,5};
    int res = BinarySearch(nums, 3);
    cout << res << endl;
    return 0;
}
