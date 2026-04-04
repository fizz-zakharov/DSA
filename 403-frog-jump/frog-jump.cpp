class Solution {
private:
    bool fn(int i,int jump,vector<int>&v,map<int,int>&m,int n,vector<vector<int>>&dp){
        if(i>=n-1)return false;
        if(jump>=n||jump<=0)return false;
        if(m.find(v[i]+jump)==m.end())return false;
        if(v[i]+jump==v[n-1])return true;   
        if(dp[i][jump]!=-1)return dp[i][jump];

        int ni=m[v[i]+jump];             

        bool a=fn(ni,jump-1,v,m,n,dp);
        bool b=fn(ni,jump,v,m,n,dp);
        bool c=fn(ni,jump+1,v,m,n,dp);

        return dp[i][jump]= (a||b||c);
    }
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        map<int,int> ind;
        for(int i=0;i<n;i++){
            ind[stones[i]]=i;
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fn(0,1,stones,ind,n,dp);
    }
};