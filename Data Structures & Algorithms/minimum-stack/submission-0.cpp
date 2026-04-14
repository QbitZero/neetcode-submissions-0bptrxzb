class MinStack {
private:
    stack<pair<int, int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val, val});
            return;
        }
        int mn = min(st.top().second, val);
        st.push({val, mn});
    }
    
    void pop() {
        if(!st.empty())
            st.pop();
    }
    
    int top() {
        return st.empty() ? -1 : st.top().first;
    }
    
    int getMin() {
        return st.empty() ? -1 : st.top().second;
    }
};
