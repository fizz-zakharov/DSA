class Solution {
private:
    int fn(int i,int state,vector<int>&v,vector<vector<int>>&dp){
        int n=v.size();
        if(i<0)return 0;
        if(dp[i][state]!=-1)return dp[i][state];
        //state=0 -> start subrray
        //state=1 -> cur element should be lesser than prev el
        //state=2 -> cur element should be greater than prev el
        int a=0;
        if(state==0){
            //start sub
            a=1+fn(i-1,1,v,dp); //next el should be lesser
            a=max(a,1+fn(i-1,2,v,dp)); //next el should be greater

            a=max(a,fn(i-1,state,v,dp)); //skip this
        }
        if(state==1){
            if(i<n-1&&v[i]<v[i+1])a=max(a,1+fn(i-1,2,v,dp)); //next el should be greater
            else return a;
        }
        if(state==2){
            if(i<n-1&&v[i]>v[i+1])a=max(a,1+fn(i-1,1,v,dp)); //next el should be lesser
            else return a;
        }
        return dp[i][state] = a;
    }
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        return fn(n-1,0,arr,dp);
    }
};