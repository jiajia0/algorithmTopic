class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<bool>> q(8, vector<bool>(8, false)); // 用来存放queen的位置
        vector<vector<int>> res;
        for(vector<int> queen : queens) {
            q[queen[0]][queen[1]] = true;
        }
        
        for(int j = -1; j < 2; ++j) {
            for(int k = -1; k < 2; ++k) {
                for(int i = 0 ; i < 8; ++i) {
                    if(j == 0 && k == 0)
                        continue;
                    int x = king[0] + k * i;
                    int y = king[1] + j * i;
                    if(x >= 0 && x <=7 && y >= 0 && y <= 7) {
                        if(q[x][y] == true) {
                            //cout << x << " " << y << endl;
                            res.push_back({x, y});
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};