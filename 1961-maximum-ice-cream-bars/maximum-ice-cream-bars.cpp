class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        vector<int> v(1e5+1);
        for(int i=0;i<n;i++){
            v[costs[i]]++;
        }
        int j=0;
        for(int i=0;i<=1e5;i++){
            if(v[i]>0){
                while(v[i]){
                    costs[j]=i;
                    v[i]--;
                    j++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(coins-costs[i]>=0){
                ans++;
                coins-=costs[i];
            }
        }
        return ans;
        
    }
};