class Solution {
private:
    int fn(int i,int budget,int rem,vector<vector<int>>&v,vector<vector<int>>&dp){
        if(i>=v.size()){
            return budget/rem;
        }
        if(dp[i][budget]!=-1)return dp[i][budget];
        int price=v[i][0];
        int free=v[i][1];
        //take
        int a=INT_MIN;
        if(price<=budget){
            a=max(a,1+free+fn(i+1,budget-price,rem,v,dp));
        }
        //not take
        int b=fn(i+1,budget,rem,v,dp);
        return dp[i][budget]=max(a,b);
    }
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<vector<int>> v;
        int rem=INT_MAX;
        for(int i=0;i<n;i++){
            int factor=items[i][0];
            int price=items[i][1];
            int free=0;
            rem=min(rem,price);
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(items[j][0]%factor==0)free++;
            }
            v.push_back({price,free});
        }
        vector<vector<int>> dp(n,vector<int>(budget+1,-1));
        return fn(0,budget,rem,v,dp);
    }
};