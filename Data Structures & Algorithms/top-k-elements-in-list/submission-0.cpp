class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        for(int &num: nums)
            countMap[num]++;
        
        vector<pair<int, int>> sortedCount;
        for(auto &[num, count]: countMap){
            sortedCount.push_back({count, num});
        }
        sort(sortedCount.begin(), sortedCount.end(), greater<pair<int, int>>());
        vector<int> result;
        for(pair<int,int> &p: sortedCount) {
            result.push_back(p.second);
            if(result.size() == k)
                break;
        }
        return result;
    }
};
