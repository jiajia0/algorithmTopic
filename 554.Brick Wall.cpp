#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int maxBrick = wall.size();//最大的层次.
        int minBrick = wall.size();//最小的层次，默认为最大层次。
        unordered_map<int,int> width;//用来保存每个长度对应的个数。
        int sum;//用来计算左边的砖的长度
        for(int i = 0; i < wall.size(); i++) {//分别循环每层。
            sum = 0;
            for(int j = 0; j < wall[i].size() - 1; j++) {//分别比较每层里面的砖。需要减去1，因为不需要计算总的宽度。
                sum += wall[i][j];//得到当前左边转的长度。
                width[sum]++;//当前左边长度在map中+1.
                //cout << sum << ", ";
                //cout << width[sum] << "\n";
                minBrick = min(minBrick,maxBrick - width[sum]);
            }
            //cout << endl << endl;
        }
        //cout << minBrick;
        return minBrick;
    }
};

int main() {
    Solution s;
    vector<vector<int>> wall;
    vector<int> a1;
    vector<int> a2;
    vector<int> a3;
    vector<int> a4;
    vector<int> a5;
    vector<int> a6;

    /*a1.push_back(1);
    a2.push_back(1);
    a3.push_back(1);*/

    a1.push_back(1);
    a1.push_back(2);
    a1.push_back(2);
    a1.push_back(1);

    a2.push_back(3);
    a2.push_back(1);
    a2.push_back(2);

    a3.push_back(1);
    a3.push_back(3);
    a3.push_back(2);

    a4.push_back(2);
    a4.push_back(4);

    a5.push_back(3);
    a5.push_back(1);
    a5.push_back(2);

    a6.push_back(1);
    a6.push_back(3);
    a6.push_back(1);
    a6.push_back(1);

    wall.push_back(a1);
    wall.push_back(a2);
    wall.push_back(a3);
    wall.push_back(a4);
    wall.push_back(a5);
    wall.push_back(a6);
    s.leastBricks(wall);
}
