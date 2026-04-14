class MinStack {
private:
    stack<int> st;

public:
    MinStack() {}

    void push(int val) {
        st.push(val);   // always push
    }

    void pop() {
        if(st.empty()) return;
        st.pop();
    }

    int top() {
        if(st.empty()) return -1;
        return st.top();   // return element, not index
    }

    int getMin() {
        if(st.empty()){
            cout << "its underflow";
            return -1;
        }

        stack<int> temp = st;
        int min = temp.top();

        while(!temp.empty()){
            if(temp.top() < min){
                min = temp.top();
            }
            temp.pop();
        }

        return min;
    }
};