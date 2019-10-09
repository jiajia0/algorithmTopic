class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> m;
        int k = 0;
        for(int n : arr1) {
            m[n]++;
        }
        //vector<int> res;
        for(int n : arr2) {
            for(int i = 0; i < m[n]; i++) {
                arr1[k++] = n;
            }
            m[n] = 0;
        }
        for(auto it = m.begin(); it != m.end(); it++) {
            for(int i = 0; i < it->second; i++) {
                arr1[k++] = it->first;
            }
        }
        return arr1;
    }
};