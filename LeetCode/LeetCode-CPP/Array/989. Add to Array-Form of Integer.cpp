#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int i = A.size()-1;
        vector<int> ans;
        while(K || i>=0) {
            if(i >= 0)
                K += A[i];
            ans.push_back(K%10);
            K /= 10;
            i--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};*/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int i = A.size() - 1;
        int car = 0;
        int x = 0;
        while(i > 0 || K > 0) {
            if(i < 0) {
                x = 0;
            } else {
                x = A[i];
            }

            K += x;

            if(i >= 0) {
                A[i] = K%10;
            } else {
                A.insert(A.begin(),K%10);
            }

            K /= 10;

            i--;

        }
        return A;
    }
};

int main() {
    Solution s;
    vector<int> A = {6};
    int K = 809;
    vector<int> ans = s.addToArrayForm(A, K);
    for(int i : ans)
        cout << i << " ";
    return 0;
}
