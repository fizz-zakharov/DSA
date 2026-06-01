class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        int ans=0;
        sort(cost.begin(),cost.end());
        int c=0;
        for(int i=n-1;i>=0;i--){
            if(c==2){
                c=0;
                continue;
            }
            ans+=cost[i];
            c++;
        }
        return ans;
    }
};