class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int gsum=0,csum=0;
        for(int i=0;i<n;i++){
            gsum+=gas[i];
            csum+=cost[i];
        }
        if(csum>gsum)return -1;
        int curgas=0;
        int ans=-1;
        for(int i=0;i<n;i++){
            if(gas[i]<cost[i])continue;
            ans=i;
            curgas=gas[i];
            while(i<n && curgas>=cost[i]){
                curgas-=cost[i];
                i++;
                if(i==n)return ans;
                curgas+=gas[i];
            }
        }
        return 0;
    }
};