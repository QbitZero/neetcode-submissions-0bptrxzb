class Solution {
public:
    bool isPalindrome(string s) {
        string refined;
        for(char &c: s){
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
                refined.push_back(c);
        }
        s = refined;
        int n = s.length();
        for(int front = 0, back = n - 1; front < back; front++, back--){
            if(tolower(s[front]) != tolower(s[back]))
                return false;
        }
        return true;
    }
};
