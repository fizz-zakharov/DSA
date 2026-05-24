class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)v.push_back({arr[i],i});
        sort(v.begin(),v.end());
        vector<int> dp(n,1);

        for(int i=0;i<n;i++){
            int val=v[i].first;
            int ind=v[i].second;
            for(int j=ind-1;j>=max(0,ind-d);j--){
                if(arr[j]>=arr[ind])break;
                dp[ind]=max(dp[ind],1+dp[j]);
            }
            for(int j=ind+1;j<=min(n-1,ind+d);j++){
                if(arr[j]>=arr[ind])break;
                dp[ind]=max(dp[ind],1+dp[j]);
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)ans=max(ans,dp[i]);
        return ans;
        
    }
};