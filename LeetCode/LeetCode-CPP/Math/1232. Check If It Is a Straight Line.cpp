class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double coor = (coordinates[1][1] - coordinates[0][1]) / double (coordinates[1][0] - coordinates[0][0]);
        
        for(int i = 2; i < coordinates.size(); i++) {
            double c = (coordinates[i][1] - coordinates[i - 1][1]) / double (coordinates[i][0] - coordinates[i - 1][0]);
            if(c != coor)
                return false;
        }
        return true;
    }
};