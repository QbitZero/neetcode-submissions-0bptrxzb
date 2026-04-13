class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<vector<int>, vector<string>> groups;
        for(string &str: strs) {
            vector<int> key(26, 0);
            for(char &c: str) {
                key[c - 'a']++;
            }
            groups[key].push_back(str);
        }
        for(auto &[key, group]: groups) {
            result.push_back(group);
        }
        return result;
    }
};
