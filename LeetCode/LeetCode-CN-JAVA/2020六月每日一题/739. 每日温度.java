class Solution {
    public int[] dailyTemperatures(int[] T) {
        int[] ans = new int[T.length];
        Stack<Integer> stk = new Stack<Integer>();
        for(int i = T.length - 1; i >= 0; i--) {
            // 栈中保存比当前气温高的位置
            while(!stk.empty() && T[i] >= T[stk.peek()]) {
                stk.pop();
            }
            // 如果栈为空则说明没有比当前气温高，记为0.否则计算出最近一个比当前气温高距离目前的距离。
            ans[i] = stk.empty() ? 0 : stk.peek() - i;
            stk.push(i);
        }
        return ans;
    }
}