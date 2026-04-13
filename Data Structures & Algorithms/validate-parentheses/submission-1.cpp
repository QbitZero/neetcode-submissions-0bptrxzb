class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> mp = {
            {'(' , 1},
            {')', -1},
            {'[' , 2},
            {']', -2},
            {'{' , 3},
            {'}', -3},
        };

        int n = s.length();
        stack<char> st;
        for(int i = 0; i < n; i++){
            if(st.empty() || mp[s[i]] > 0)
                st.push(s[i]);
            else if(mp[st.top()] + mp[s[i]] == 0){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};
