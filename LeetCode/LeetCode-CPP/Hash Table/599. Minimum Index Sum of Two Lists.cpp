#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        unordered_map<string, int> words;
        for(int i = 0; i < list1.size(); i++) { // 记录第一组的index
            words[list1[i]] = i;
        }
        int minindex = INT_MAX;
        for(int i = 0; i < list2.size(); i++) {
            if(words.count(list2[i]) != 0) { // 代表两组共同出现过的名字
                //cout << list2[i] << " " << i + words[list2[i]] << " " << minindex <<  endl;
                if(i + words[list2[i]] < minindex) {
                    minindex = words[list2[i]] + i;
                    ans.clear();
                    ans.push_back(list2[i]);
                } else if(i + words[list2[i]] == minindex) // 可能出现sum index 相同 并且 least
                    ans.push_back(list2[i]);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> list2 = {"KNN","KFC","Burger King","Tapioca Express","Shogun"};
    vector<string> ans = s.findRestaurant(list1, list2);
    for(string word : ans)
        cout << word << " ";
    return 0;
}
