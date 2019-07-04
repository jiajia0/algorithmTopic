#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int> q;
        for(int i : arr) {
            q.push(i);
        }
        for(int i = 0; i < arr.size(); i++) {
            int top = q.front();

            if(top != 0) {
                arr[i] = top;
            } else {
                arr[i++] = top;
                if(i < arr.size())
                    arr[i] = top;
            }
            q.pop();
        }
    }
};


int main () {
    Solution s;
    vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};
    s.duplicateZeros(arr);
    return 0;
}
