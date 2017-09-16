#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int,int> temp;

        for(auto num : nums1) {
            temp[num]++;
        }

        for(auto num : nums2) {
            if(temp[num]-- > 0) result.push_back(num);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> v1 = {1,2,3,1};
    vector<int> v2 = {1,1};

    vector<int> res = s.intersect(v1,v2);
    for(int num : res) {
        cout << num << endl;
    }
}
