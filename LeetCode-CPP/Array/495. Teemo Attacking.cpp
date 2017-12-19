#include <iostream>
#include <vector>

using namespace std;

/*class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {

        if(duration == 0 || timeSeries.empty() || timeSeries.size() == 0) {
            return 0;
        }

        int time = 0;
        int startTime = timeSeries[0];//记录开始时间
        int endTime = timeSeries[0] + duration;//记录结束时间

        for(int i=1; i < timeSeries.size(); i++) {
            //如果现在的时间大于结束时间，就加上一个间隔时间，并且重置开始时间
            if(timeSeries[i] > endTime) {
                time += endTime - startTime;
                startTime = timeSeries[i];
            }
            //计算下一个结束时间
            endTime = timeSeries[i] + duration;
        }

        // 计算最后一次结束的时间和开始时间的间隔
        time += endTime - startTime;

        return time;
    }
};*/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int time = duration * timeSeries.size();//计算总的时间
        for(int i=1; i < timeSeries.size(); i++) {
            // 如果两次时间有叠加，将叠加的时间减去
            time -= max(0,duration - (timeSeries[i] - timeSeries[i-1]));
        }
        return time;
    }
};

int main() {
    Solution s;
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(3);


    int n = s.findPoisonedDuration(nums,5);
    cout << n;
    return 0;
}

