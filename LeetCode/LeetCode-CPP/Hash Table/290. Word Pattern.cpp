class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, int> s;
        unordered_map<char, int> p;
        istringstream ss(str);
        string word;
        int i = 0;
        while(ss >> word) {
            //cout << pattern[i] << " " << word << endl;
            if(p[pattern[i]] != s[word] || i == pattern.length())
                return false;
            p[pattern[i]] = i + 1;
            s[word] = i + 1;
            i++;
        }
        return i==pattern.length();
    }
};