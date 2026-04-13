class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int maxLen = 0;
        int l = 0;
        int r = 0;
        while(r < s.length()){
            if(seen.count(s[r])){
                maxLen = max(maxLen, r - l);
                while(seen.count(s[r])){
                    seen.erase(s[l]);
                    l++;
                }
            }
            seen.insert(s[r]);
            r++;
        }
        return max(maxLen, r - l);
    }
};
