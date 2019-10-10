/*
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int l = 0;
        int r = 0;
        int origin_start = start;
        while(start != destination) {
            r += distance[start];
            start = (++start) % distance.size();
        }
        while(origin_start != destination) {
            // 先计算位置，再找距离
            origin_start = origin_start == 0 ? distance.size() - 1 : --origin_start;
            l += distance[origin_start];
        }
        return min(l, r);
    }
};
*/

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(start > destination)
            swap(start, destination);
        int res = 0, total = 0;
        for(int i = 0; i < distance.size(); i++) {
            if(i >= start && i < destination)
                res += distance[i];
            total += distance[i];
        }
        return min(res, total - res);
    }
};