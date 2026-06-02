class FreqStack {
public:
    FreqStack() {
        
    }
    map<int,int> m;
    map<int,stack<int>> mx;
    int maxfreq=INT_MIN;
    void push(int val) {
        m[val]++;
        maxfreq=max(maxfreq,m[val]);
        mx[m[val]].push(val);
    }
    
    int pop() {
        int num=mx[maxfreq].top();
        mx[maxfreq].pop();
        if(mx[maxfreq].empty()){
            mx.erase(maxfreq);
            maxfreq--;
        }
        m[num]--;
        return num;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */