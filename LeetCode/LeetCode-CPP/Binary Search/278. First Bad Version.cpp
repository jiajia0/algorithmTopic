#include <iostream>

using namespace std;

class Solution {
public:
    // 假设第一个BadVersion是4
    bool isBadVersion(int version){
        if(version < 4)
            return false;
        return true;
    }

    int firstBadVersion(int n) {
        int start=0,end = n;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if(isBadVersion(mid)) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if(isBadVersion(start))
            return start;
        return end;
    }
};

int main() {
    Solution s;
    int res = s.firstBadVersion(5);
    cout << res << endl;
    return 0;
}
