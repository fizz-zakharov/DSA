class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();

        map<int,int> ind;
        for(int i=0;i<n;i++)ind[arr[i]]=i;

        vector<vector<int>> dp(n,vector<int>(n,2));

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int num=arr[i]-arr[j];
                if(ind.count(num)&&ind[num]<j){
                    dp[i][j]=1+dp[j][ind[num]];
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return (ans!=2)?ans:0;

    }
};