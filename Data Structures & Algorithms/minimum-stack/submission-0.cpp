class MinStack {
public:
    stack<int> mainSt;
    stack<int> minSt;
    MinStack() {
        
    }
    
    void push(int val) {
        if(minSt.empty() || val <= minSt.top()){
            minSt.push(val);
        }
        mainSt.push(val);
    }
    
    void pop() {
        if(mainSt.top() == minSt.top()){
            minSt.pop();
        }
        mainSt.pop();
    }
    
    int top() {
        return mainSt.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
