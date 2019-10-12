/*
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = 0;
        int count = 0;
        for(int i = 0; i < seats.size(); i++) {
            if(seats[i] == 0) {
                count++;
                // 处理最后全是0的情况
                if(i == seats.size() - 1 && count >= ans)
                    ans = count;
            } else {
                if(count >= ans) {
                    if(i == count) {// 处理刚开始全是0的情况
                        ans = count;
                    } else {
                        ans = max(int(ceil(count / 2.0)), ans);
                    }
                }
                count = 0;
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int res = 1;
        int last = -1;
        for(int i = 0; i < n; i++) {
            if(seats[i] == 1) {
                res = last < 0 ? i : max(res, (i - last) / 2);
                last = i;
            }
        }
        // 处理最后面全是0的情况
        res = max(res, n - last - 1);
        return res;
    }
};