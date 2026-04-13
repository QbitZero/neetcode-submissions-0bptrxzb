class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        
        vector<int> hash1(26, 0);
        for(char &c: s1){
            hash1[c - 'a']++;
        }
        vector<int> hash2(26, 0);
        int win = s1.length();
        for(int i = 0; i < win; i++)
            hash2[s2[i] - 'a']++;
        
        for(int i = win; i < s2.length(); i++){
            if(hash1 == hash2)
                return true;
            
            hash2[s2[i - win] - 'a']--;
            hash2[s2[i] - 'a']++;
        }
        return hash1 == hash2;
    }
};
