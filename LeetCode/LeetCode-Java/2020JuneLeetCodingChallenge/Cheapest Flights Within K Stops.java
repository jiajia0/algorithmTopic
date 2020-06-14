class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        // bellman ford
        int[] prices = new int[n];
        Arrays.fill(prices, Integer.MAX_VALUE);
        prices[src] = 0; // 将src设置为0
        for(int i = 0; i <= K; i++) {
            // 需要单独复制一份用来查看原来的记录，来限制一次只走一步，如果修改原来的数组，则遍历完所有的边相当于走了很多步.eg:0->1 100, 1->2 100,0->2 500, 求0->2 且K=0.
            int[] temp = Arrays.copyOf(prices, n);
            for(int[] e : flights) {
                if(prices[e[0]] != Integer.MAX_VALUE) { // 如果==MAX则说明之前无法到达该中转点，所以无需比较
                    temp[e[1]] = Math.min(temp[e[1]], prices[e[0]] + e[2]);
                }
            }
            prices = temp;
        }
        return prices[dst] == Integer.MAX_VALUE ? -1 : prices[dst];
    }
}