class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // bellman ford
        vector<int> c(n,INT_MAX);
        c[src] = 0;
        // 停顿K次，则需要K+1个边
        for(int i = 0; i <= K; i++) {
            vector<int> temp(c); // 拷贝一份数据用来计算
            for(auto e : flights) {
                // 到达下一个点的距离 = min(目前到达下一个点的距离，原来到达中转点+ 中转点到下一个点 的距离 );
                int k = c[e[0]] == INT_MAX ? INT_MAX : c[e[0]] + e[2];
                temp[e[1]] = min(temp[e[1]], k); // 遍历所有的边，计算出到达下一个点的最小费用
            }
                
            c = temp; // 更新距离
        }
        return c[dst] == INT_MAX ? -1 : c[dst];
    }
};