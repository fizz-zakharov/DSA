class RideSharingSystem {
private:
    queue<int> dq;
    queue<int> rq;
public:
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rq.push(riderId);
    }
    
    void addDriver(int driverId) {
        dq.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(!rq.empty()&&!dq.empty()){
            int r=rq.front();
            int d=dq.front();
            rq.pop();
            dq.pop();
            return {d,r};
        }
        return {-1,-1};
    }
    
    void cancelRider(int riderId) {
        queue<int> temp;
        
        while (!rq.empty()) {
            int curr = rq.front();
            rq.pop();
            
            if (curr != riderId) {
                temp.push(curr);
            }
        }
        
        rq = temp;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */