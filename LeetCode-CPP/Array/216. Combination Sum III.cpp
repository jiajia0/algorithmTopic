#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;


    }
};


int main() {
    Solution s;

    vector<vector<int>> result = s.combinationSum3(3,9);

    for(int i=0;i<result.size();i++) {
        for(int j=0;j<result[0].size();j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}




