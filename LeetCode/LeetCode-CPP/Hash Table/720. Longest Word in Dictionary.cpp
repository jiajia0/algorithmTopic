#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        string ans = "";
        unordered_set<string> prefixes;
        for(string word: words)
            prefixes.insert(word);
        for(string word : words) {
            int flag = 1;
            string prefixe = "";
            for(int i = 0; i < word.size(); i++) {
                prefixe += word[i];
                if(prefixes.find(prefixe) == prefixes.end()) { // 说明当前前缀能够在其他单词中找不到
                    if(i != word.size() - 1) { // 说明没有走到最后 , 不符合条件
                        flag = 0;
                        prefixes.insert(word);
                        break;
                    } else  { // 说明除了最后一个字符之外其他都能够找到，则此时应该是符合
                        prefixes.insert(word);
                    }
                }
            }
            if(flag) {
                if(word.size() > ans.size())
                    ans = word;
                else if(word.size() == ans.size()) { // 如果两个单词长度相等，则对比他们的字典顺序
                    //cout << word << " " << ans << endl;
                    for(int i = 0; i < word.size(); i++) {
                        if(word[i] < ans[i]) {
                            //cout << word[i] << "," << ans[i] << endl;
                            ans = word;
                            break;
                        } else if(word[i] > ans[i])
                            break;;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    string ans = s.longestWord(words);
    cout << ans << endl;
    return 0;
}
