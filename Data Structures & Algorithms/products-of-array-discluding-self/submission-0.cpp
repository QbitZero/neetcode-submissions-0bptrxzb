class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> lTor(n, 1);
        vector<int> rTol(n, 1);
        for(int i = n - 1; i >= 0 ; i--){
            rTol[i] *= nums[i];
            if(i + 1 < n)
                rTol[i] *= rTol[i + 1];
        }
        for(int i = 0; i < n; i++){
            lTor[i] *= nums[i];
            if(i - 1 >= 0)
                lTor[i] *= lTor[i - 1];
        }
        vector<int> result(n, 1);
        for(int i = 0; i < n; i++){
            if(i - 1 >= 0)
                result[i] *= lTor[i - 1];
            if(i + 1 < n)
                result[i] *= rTol[i + 1];
        }
        return result;
    }
};
