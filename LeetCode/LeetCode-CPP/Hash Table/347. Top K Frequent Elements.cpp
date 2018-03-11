#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(!nums.size() || nums.size()==k) return nums;

        unordered_map<int,int> frequentMap;// 用来统计每个元素出现的频率
        for(int i=0;i<nums.size();i++)
            frequentMap[nums[i]]++;// 进行统计

        vector<vector<int>> bucket(nums.size()+1);// 创建一个桶
        for(auto kv : frequentMap) {// 遍历统计数据
            bucket[kv.second].push_back(kv.first);// 将其放入桶中
        }

        vector<int> result;
        for(int i=bucket.size()-1;i>=0;i--) {
            for(int j=0;j<bucket[i].size();j++){
                if(!k) return result;// 如果已经找出了所有的K个，则直接返回
                result.push_back(bucket[i][j]);
                k--;
            }
        }
        return result;
    }
};


/*class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(!nums.size() || nums.size()==k) return nums;
        unordered_map<int,int> frequentMap;// 用来统计频率
        for(int i=0;i<nums.size();i++)
            frequentMap[nums[i]]++;// 进行统计

        vector<int> result;
        priority_queue<pair<int,int>> pq;// 使用优先队列，默认数字越小优先级越大，所以频率大的靠前
        for(auto kv : frequentMap) {
            pq.push(make_pair(kv.second,kv.first));
        }

        while(!pq.empty() && k--) {// 截取前K个
            //cout << pq.top().first << "," << pq.top().second << endl;
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};*/


int main() {
    Solution s;
    vector<int> nums = {2,2,3,3,1,4,4,4};
    vector<int> result = s.topKFrequent(nums,2);
    for(int item : result)
        cout << item << ",";
    return 0;
}
