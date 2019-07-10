#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


/*
Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
Output: ["girl","student"]
*/

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> result;
        vector<string> words;

        stringstream ss(text);
        string str;

        while(ss >> str) {
            words.push_back(str);
        }

        /*for(char ch : text) {
            if(ch != ' ')
                str += ch;
            else {
                words.push_back(str);
                str = "";
            }
        }
        words.push_back(str);*/
        for(int i=0; i < words.size() - 2; i++) {
            //cout << words[i] << ", " << words[i+1] << endl;
            if(words[i] == first && words[i+1] == second)
                result.push_back(words[i+2]);
        }
        return result;
    }
};

int main() {
    Solution s;
    string text = "ypkk lnlqhmaohv lnlqhmaohv lnlqhmaohv ypkk ypkk ypkk ypkk ypkk ypkk lnlqhmaohv lnlqhmaohv lnlqhmaohv lnlqhmaohv ypkk ypkk ypkk lnlqhmaohv lnlqhmaohv ypkk";
    string first = "lnlqhmaohv";
    string second = "ypkk";
    vector<string> result = s.findOcurrences(text, first ,second);
    cout << result.size();
    for(string str : result)
        cout << str << endl;
    return 0;
}
