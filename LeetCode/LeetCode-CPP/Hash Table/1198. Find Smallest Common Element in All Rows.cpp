class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        map<int,int> hash;
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                hash[mat[i][j]]++;
            }
        }
        
        for(auto it = hash.begin(); it != hash.end(); it++) {
            if(it->second == mat.size())
                return it->first;
        }
        return -1;
    }
};