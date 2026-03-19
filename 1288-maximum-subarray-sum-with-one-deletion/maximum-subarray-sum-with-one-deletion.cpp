class Solution {
private:
    int fn(int i,int state,vector<int>&v,vector<vector<int>>&dp){
        if(i<0){
            if(state==0)return INT_MIN;
            return 0;
        }
        if(dp[i][state]!=-1)return dp[i][state];
        //state 1 (0)-> will start with that element and we'll either pick or not pick
        //state 2 (1)->we have started picking and we have one option of skipping at most 1 el
        //state 3 (2)-> now we have skipped one element and we have to pick all the elements
        int ans=INT_MIN;
        if(state==0){
            //pick
            ans=v[i]+fn(i-1,1,v,dp);

            //not pick
            ans=max(ans,fn(i-1,0,v,dp));
        }
        if(state==1){
            //keep picking
            ans=v[i]+fn(i-1,1,v,dp);

            //skip one el
            ans=max(ans,fn(i-1,2,v,dp));
            ans=max(ans,0);
        }
        if(state==2){
            //keep picking
            ans=max(ans,v[i]+fn(i-1,2,v,dp));
            ans=max(ans,0);
        }
        return dp[i][state]= ans;
    }
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));

        return fn(n-1,0,arr,dp);
    }
};