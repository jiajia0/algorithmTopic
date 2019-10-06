/*
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        unordered_map<int,int> m;
        vector<int> res;
        for(int n : arr1) {
            m[n]++;
        }
        for(int n : arr2) {
            m[n]++;
        }
        for(int n : arr3) {
            if(m[n] == 2) {
                res.push_back(n);
            }
        }
        return res;
    }
};
*/
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int i = 0, j = 0, k = 0;
        vector<int> res;
        while(i < arr1.size() && j < arr2.size() && k < arr3.size()) {
            if(arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                res.push_back(arr1[i]);
                i++;
                k++;
                j++;
            } else if(arr1[i] < arr2[j]) {
                i++;
            } else if(arr2[j] < arr3[k]) {
                j++;
            } else {
                k++;
            }
        }
        return res;
    }
};