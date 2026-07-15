class MinStack {
        stack<int> min;
        stack<int> stack;
public:
    MinStack() {  
   
    }
    
    void push(int value) {
        stack.push(value);
        if (min.empty() ||stack.top () <= min.top() ) min.push(value);
    }
    
    void pop() {
        if(stack.top() == min.top()) min.pop();
        stack.pop();
    }
    
    int top() {
       return stack.top();
    }
    
    int getMin() {
        return min.top();
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