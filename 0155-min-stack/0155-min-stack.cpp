class MinStack {
public:
    stack<int> st;
    vector<int> vec;
    int i=-1;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(vec.empty() || value<vec[i]){
            vec.push_back(value);
            i++;
        }
        else{
            vec.push_back(vec[i]);
            i++;
        }
    }
    
    void pop() {
        st.pop();
        vec.pop_back();
        i--;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return vec[i];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */