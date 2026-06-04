class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>> st;
    int ind=-1;
    int count=-1;
    bool flag=true;
    int next(int price) {
        count++;
        while(!st.empty() && price>=st.top().first){
            st.pop();
        }
        if(flag){
            st.push({price,count});
            flag=false;
            return 1;
        }
        int k=-1;
        if(!st.empty())k=st.top().second;
        st.push({price,count});
        return count-k;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */