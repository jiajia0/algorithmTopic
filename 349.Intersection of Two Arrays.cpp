#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> temp(nums1.begin(),nums1.end());

        for(auto num : nums2) {
            if(temp.count(num)) result.insert(num);
        }

        return vector<int>(result.begin(),result.end());

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

