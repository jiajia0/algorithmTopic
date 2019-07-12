#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> ans;
        unordered_map<string,int> words;
        stringstream ss1(A);
        stringstream ss2(B);
        string temp;
        while(ss1 >> temp)
            words[temp]++;
        while(ss2 >> temp)
            words[temp]++;
        for(auto it=words.begin();it != words.end();it++) {
            if(it->second == 1)
                ans.push_back(it->first);
        }
        return ans;
    }
};

int main() {
    Solution s;
    string A = "apple apple";
    string B = "banana";
    vector<string> ans = s.uncommonFromSentences(A, B);
    for(string str : ans)
        cout << str << endl;
    return 0;
}
