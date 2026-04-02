class Solution {
private:
    long long fn(int i,int j,int state,vector<vector<int>>&v,vector<vector<vector<long long>>>&dp){
        if(i==0&&j==0){
            if(v[i][j]>=0||state==2)return v[i][j];
            else return max((long long)v[i][j],(long long)0);
        }
        if(i<0||j<0)return -1e9;
        if(dp[i][j][state]!=-1e9)return dp[i][j][state];

        long long a=-1e9,b=-1e9;
        if(state==0){
            if(v[i][j]>=0){
                //left
                a=v[i][j]+fn(i-1,j,state,v,dp);
                //up
                b=v[i][j]+fn(i,j-1,state,v,dp);
            }
            else{
                //skip
                a=fn(i-1,j,1,v,dp);
                b=fn(i,j-1,1,v,dp);

                //take
                a=max(a,v[i][j]+fn(i-1,j,state,v,dp));
                b=max(b,v[i][j]+fn(i,j-1,state,v,dp));
            }
        }
        if(state==1){
            if(v[i][j]>=0){
                //left
                a=v[i][j]+fn(i-1,j,state,v,dp);
                //up
                b=v[i][j]+fn(i,j-1,state,v,dp);
            }
            else{
                //skip
                a=fn(i-1,j,2,v,dp);
                b=fn(i,j-1,2,v,dp);

                //take
                a=max(a,v[i][j]+fn(i-1,j,state,v,dp));
                b=max(b,v[i][j]+fn(i,j-1,state,v,dp));
            }
        }
        if(state==2){
            //left
            a=v[i][j]+fn(i-1,j,state,v,dp);
            //up
            b=v[i][j]+fn(i,j-1,state,v,dp);
        }
        return dp[i][j][state]= max(a,b);
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size();
        int n=coins[0].size();
        vector<vector<vector<long long>>> dp(m,vector<vector<long long>>(n,vector<long long>(3,-1e9)));

        return fn(m-1,n-1,0,coins,dp);
    }
};