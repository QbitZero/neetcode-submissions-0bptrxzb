class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st;
        for(int curr = 0; curr < n; curr++){
            while(!st.empty() && temperatures[st.top()] < temperatures[curr]){
                result[st.top()] = curr - st.top();
                st.pop();
            }
            st.push(curr);
        }
        return result;
    }
};
