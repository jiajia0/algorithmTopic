class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end()); // ох╫ЬппеепР
        int minimum = INT_MAX;
        for(int i = 0 ; i < arr.size() - 1; i++) {
            minimum = min(minimum, abs(arr[i] - arr[i+1]));
        }
        
        vector<vector<int>> res;
        for(int i = 0 ; i < arr.size() - 1; i++) {
            if(abs(arr[i] - arr[i+1]) == minimum) {
                vector<int> temp = {arr[i], arr[i+1]};
                res.push_back(temp);
            }
        }
        return res;
    }
};