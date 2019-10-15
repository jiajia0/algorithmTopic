class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int oldColor, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor)
            return;
        image[sr][sc] = newColor; // 修改当前位置为newColor
        for(int i = -1; i < 2; i++) {
            for(int j = -1; j < 2; j++) {
                if(abs(i) + abs(j) != 1) {
                    continue;
                }    
                
                int n_r = sr + i;
                int n_c = sc + j;
                if(n_r >= 0 && n_r < image.size() && n_c >= 0 && n_c < image[0].size() && image[n_r][n_c] == oldColor) {
                    dfs(image, oldColor, n_r, n_c, newColor);
                }
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        dfs(image, image[sr][sc], sr, sc, newColor);
        return image;
    }
};