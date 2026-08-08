class Solution {
private:
    void fn(int node,vector<vector<int>>& adj,vector<vector<int>>&dp){
        int c=0;
        for(auto it:adj[node]){
            if(c==0){
                c++;
                fn(it,adj,dp);
                dp[node][0]=1+dp[it][0]+dp[it][1];
            }
            else{
                fn(it,adj,dp);
                dp[node][1]=1+dp[it][0]+dp[it][1];
            }
        }
        return;
    }
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(parents[i]==-1)continue;
            adj[parents[i]].push_back(i);
        }
        vector<vector<int>> dp(n,vector<int>(2,0));
        vector<long long> scores;
        fn(0,adj,dp);
        for(int i=0;i<n;i++){
            int l=dp[i][0];
            int r=dp[i][1];
            int up=n-l-r-1;
            scores.push_back((long long)max(1,l)*max(1,r)*max(1,up));
        }
        sort(scores.begin(),scores.end());
        int c=0;
        int j=n-1;
        while(j>=0 && scores[j]==scores[n-1]){
            c++;
            j--;
        }
        return c;
    }
};