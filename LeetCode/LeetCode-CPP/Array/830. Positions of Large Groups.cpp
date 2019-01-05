#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;
        int count=1;
        for(int i=0,j=1;i<S.length();i++,j++) {
            if(S[i] == S[j]) {// 如果连续两个字母相等，则统计数目加一
                count++;
            } else {
                if(count >= 3) { // 如果连续次数大于3，则加入结果中
                    //cout << "i:" << i << ",count:" << count;
                    vector<int> temp = {i-count+1,i};
                    result.push_back(temp);
                }
                count=1;
            }
        }
        return result;
    }
};*/

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int start=0, end=0, n=S.size();
        vector<vector<int>> res;
        while(end<n)
        {
            while(end<n && S[end]==S[start])// 如果当前的字符等于最开始的字符，则一直向后寻找
                end++;
            if(end-start>=3) { // 如果之间长度大于3，则加入结果
                res.push_back({start,end-1});
                //cout << "start:" << start << ",end:" << end << endl;
            }
            start=end;// 调整开始的位置
        }
        return res;
    }
};

int main() {
    Solution s;
    string str = "abcdddeeeeaabbbcd";
    vector<vector<int>> result = s.largeGroupPositions(str);
    int i,j;
    for(i=0;i<result.size();i++) {
        for(j=0;j<result[0].size();j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
