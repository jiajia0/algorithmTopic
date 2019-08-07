#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

/*class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        int i = 1;
        map<string, int> content_index; // string：文件中的content ，int：ans中的索引
        map<string, string> content_path; // 存放content第一次出现的path
        for(string path : paths) {
            stringstream ss(path);
            // 得到主目录
            string dir;
            ss >> dir;
            dir += "/";

            string file;
            while(ss >> file) {
                int s = file.find("(");
                string filename = file.substr(0, s); // 获取文件名称
                string content = file.substr(s + 1, file.size() - s - 2); // 获取文件内容
                if(content_index[content] == 0) { // 如果这个content 没有出现，则创建一个新的vector来保存对应的path
                    //cout << "新建：" << content << endl;

                    if(content_path[content] == "") { // 第一次出现
                        content_path[content] = dir + filename;
                    } else {
                        vector<string> filenames;
                        filenames.push_back(content_path[content]);
                        filenames.push_back(dir + filename);
                        ans.push_back(filenames);
                        content_index[content] = i++; // 保存的index-1就是ans中实际存放的位置
                    }

                } else { // 如果出现了index，根据map索引找到对应的vector索引
                    //cout << "重复：" << content << endl;
                    ans[content_index[content] - 1].push_back(dir + filename);
                }
            }
        }
        return ans;
    }
};*/


class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        map<string, vector<string>> table; // string：content，vector<string>：对应的path
        for(string path : paths) {
            stringstream ss(path);
            // 得到主目录
            string dir;
            ss >> dir;
            dir += "/";

            string file;
            while(ss >> file) {
                int s = file.find("(");
                string filename = file.substr(0, s); // 获取文件名称
                string content = file.substr(s + 1, file.size() - s - 2); // 获取文件内容
                table[content].push_back(dir + filename);
            }
        }
        for(auto it = table.begin(); it != table.end(); it++) {
            if(it->second.size() > 1)
                ans.push_back(it->second);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
    vector<vector<string>> ans = s.findDuplicate(paths);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
