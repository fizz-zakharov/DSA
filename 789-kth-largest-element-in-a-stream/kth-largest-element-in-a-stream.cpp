class KthLargest {
public:
    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> minheap;
    int temp;
    KthLargest(int k, vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)pq.push(nums[i]);
        temp=k;
        for(int i=0;i<k;i++){
            if(pq.empty())break;
            minheap.push(pq.top());
            pq.pop();
        }
    }
    
    int add(int val) {
        if(minheap.size()<temp){
            minheap.push(val);
            return minheap.top();
        }
        if(minheap.top()>=val)return minheap.top();
        minheap.push(val);
        minheap.pop();
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */