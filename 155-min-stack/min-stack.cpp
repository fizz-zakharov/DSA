class MinStack {
public:
    MinStack() {
        
    }
    stack<int> s;
    priority_queue<int,vector<int>,greater<int>> pq;
    unordered_map<int,int> m;
    void push(int value) {
        s.push(value);
        pq.push(value);
        m[value]++;
    }
    
    void pop() {
        m[s.top()]--;
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        while(!pq.empty()){
            if(m[pq.top()]!=0){
                return pq.top();
            }
            pq.pop();
        }
        return 0;
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