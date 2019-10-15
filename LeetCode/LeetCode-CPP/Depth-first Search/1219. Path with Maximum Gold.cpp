class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x ,int y) {
        int temp = grid[x][y];
        grid[x][y] = 0; // 暂时将该位置修改为0，代表访问过了
        int res = 0;
        for(int i = -1; i < 2; i++) {
            for(int j = -1; j < 2; j++) {
                if(abs(i) + abs(j) != 1) // 四个方向
                    continue;
                int next_x = i + x;
                int next_y = j + y;
                if(next_x >= 0 && next_x < grid.size() && next_y >= 0 && next_y < grid[0].size() && grid[next_x][next_y] != 0) {
                    res = max(grid[next_x][next_y] + dfs(grid, next_x, next_y), res);
                }
            }
        }
        grid[x][y] = temp; // 复原，可供访问
        return res;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] != 0) {
                    res = max(grid[i][j] + dfs(grid, i , j), res);
                }
            }
        }
        return res;
    }
};