class MyStack {
public:
    queue<int> st;
    MyStack() {}
    
    void push(int x) {
        int n = st.size();
        st.push(x);
        for (int i = 0; i < n; i++) {
            st.push(st.front());
            st.pop();
        }
    }
    
    int pop() {
        int x = st.front();
        st.pop();
        return x;
    }
    
    int top() {
        return st.front();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */