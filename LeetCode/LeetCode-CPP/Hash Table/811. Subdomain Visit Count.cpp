#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> result;
        map<string, int> domains;
        string temp;
        for(string str : cpdomains) { // 遍历所有的域名
            stringstream ss(str);
            int i = 1, num;
            while(ss >> temp) { // 使用空格隔开数据，第一个是访问次数， 第二个是域名
                if(i--) { // 处理数字
                    num = atoi(temp.c_str());
                } else { // 处理域名
                    domains[temp] += num;
                    // 处理子域名
                    string domain = "";
                    for(i = temp.size() - 1; i >= 0; i--) {
                        if(temp[i] != '.') {
                            domain += temp[i];
                        } else {
                            string d = domain;
                            reverse(d.begin(), d.end());
                            domains[d] += num;
                            //cout << temp << " : " << d << "," << num << endl;
                            domain += ".";
                        }
                    }
                }
            }
        }

        for(auto it = domains.begin(); it != domains.end(); it++) {
            result.push_back(to_string(it->second) + " " + it->first);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<string> cpdomains = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    vector<string> result = s.subdomainVisits(cpdomains);
    for(auto str : result) {
        cout << str << endl;
    }
    return 0;
}
