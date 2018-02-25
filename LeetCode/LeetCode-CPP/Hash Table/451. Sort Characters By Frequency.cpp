#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> chCount;// 统计各个字母出现的次数
        string ans;

        for(char c : s) chCount[c]++;

        map<int,string> bucket;// 使用map的原因是，map已经完成了排序

        for(auto it : chCount) {
            char ch = it.first;
            int n = it.second;
            bucket[n] += string(n,ch);// 添加到map中，如果该统计位置已经有元素了，则加到该位置上
        }

        // 从尾到头遍历，此时已经排序过了
        for(auto rit = bucket.rbegin();rit != bucket.rend();rit++) {
            ans += rit->second;
        }

        return ans;
    }
};

int main() {
    Solution s;
    string word = "tree";
    string result = s.frequencySort(word);
    cout << result;
    return 0;
}
