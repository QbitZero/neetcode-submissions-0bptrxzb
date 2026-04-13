class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        for(int i = 0; i < k; i++){
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            dq.push_back(i);
        }
        vector<int> result;
        for(int i = k; i < nums.size(); i++){
            result.push_back(nums[dq.front()]);
            while(!dq.empty() && (i - dq.front()) >= k)
                dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            dq.push_back(i);
        }
        result.push_back(nums[dq.front()]);
        return result;
    }
};
