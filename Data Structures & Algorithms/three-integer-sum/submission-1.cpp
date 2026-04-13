class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int target = -nums[i];
            int low = i + 1;
            int high = n - 1;
            while(low < high){
                int sum = nums[low] + nums[high];
                if(sum > target)
                    high--;
                else if(sum < target)
                    low++;
                else{
                    result.push_back({nums[low], nums[high], nums[i]});
                    low++;
                    high--;
                    while(low < high && nums[low] == nums[low - 1])
                        low++;
                }
            }
        }
        return result;
    }
};
