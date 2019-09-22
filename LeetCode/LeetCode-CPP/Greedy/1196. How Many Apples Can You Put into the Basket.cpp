class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        int res = 0;
        int weight = 0;
        sort(arr.begin(), arr.end());
        for(int num : arr) {
            weight += num;
            if(weight > 5000)
                return res;
            else
                res += 1;
        }
        return res;
    }
};