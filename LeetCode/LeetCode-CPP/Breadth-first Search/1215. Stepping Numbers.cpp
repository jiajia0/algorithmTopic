class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> res;
        queue<long> q;
        for(long i = 1; i < 10; i++) {
            q.push(i);
        }
        if(low == 0)
            res.push_back(0);
        while(!q.empty()) {
            long num = q.front();
            q.pop();
            if(num < high) {
                int last = num % 10; // 拿到最后一位
                if(last > 0)
                    q.push(num * 10 + last - 1);
                if(last < 9)
                    q.push(num * 10 + last + 1);
            }
            if(num >= low && num <= high) {
                res.push_back(num);
            }
        }
        return res;
    }
};