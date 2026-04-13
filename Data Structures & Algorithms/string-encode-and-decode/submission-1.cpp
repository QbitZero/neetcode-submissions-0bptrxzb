class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for(string &str: strs) {
            result += (to_string(str.length())) + "#" + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string currLen;
        int idx = 0;
        int n = s.length();
        while(idx < n) {
            if(isdigit(s[idx])){
                currLen.push_back(s[idx]);
                idx++;
                continue;
            }
            if(s[idx] == '#'){
                int len = stoi(currLen);
                currLen = "";
                string temp;
                for(int i = idx + 1; i < idx + len + 1; i++){
                    temp.push_back(s[i]);
                }
                result.push_back(temp);
                idx += (len + 1);
            }
        }
        return result;
    }
};
