class Solution {
public:
    bool isOperation(string &s){
        return s == "*" || s == "/" || s == "+" || s == "-";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string &token: tokens){
            if(isOperation(token)){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                if(token == "*"){
                    st.push(first * second);
                }else if(token == "/"){
                    st.push(first / second);
                }else if(token == "+"){
                    st.push(first + second);
                }else{
                    st.push(first - second);
                }
            }else{
                int numToken = stoi(token);
                st.push(numToken); 
            }
        }
        return st.top();
    }
};
