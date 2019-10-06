class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int even_num = 0;
        int odd_num = 0;
        for(int n : chips) {
            if(n % 2 == 0)
                even_num++;
            else
                odd_num++;
        }
        return min(even_num, odd_num);
    }
};