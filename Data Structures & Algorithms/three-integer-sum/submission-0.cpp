class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> result;
        for(int i = 0; i < n; i++) {
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
                    result.insert({nums[low], nums[high], nums[i]});
                    low++;
                    high--;
                }
            }
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};
