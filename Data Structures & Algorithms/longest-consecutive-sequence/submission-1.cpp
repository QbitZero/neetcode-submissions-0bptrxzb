class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        unordered_set<int> numSet;
        for(int i = 0; i < n; i++) {
            numSet.insert(nums[i]);
        }
        for(auto &num: numSet){
            int x = num;
            if(numSet.find(num - 1) == numSet.end()){
                int len = 0;
                while(numSet.find(x) != numSet.end()){
                    x++;
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};
