class Solution {
private:
    int n;
    int dp[(1<<14)+1][16];
    vector<int> ans;
    int fn(int mask,int last,vector<int>&v){
        if(mask==(1<<n)-1)return abs(last-v[0]);
        if(dp[mask][last]!=-1)return dp[mask][last];
        int cost=1e9;
        for(int j=0;j<n;j++){
            if(mask&(1<<j))continue;
            int newmask=mask|(1<<j);
            cost=min(cost,abs(last-v[j])+fn(newmask,j,v));
        }
        return dp[mask][last] = cost;
    }

    void reconstruct(int mask,int last,vector<int>&v){
        ans.push_back(last);
        if(mask==(1<<n)-1)return;

        int val=dp[mask][last];
        for(int j=0;j<n;j++){
            if(mask&(1<<j))continue;
            int newmask=mask|(1<<j);
            int cost=abs(last-v[j])+fn(newmask,j,v);
            if(cost==val){
                reconstruct(newmask,j,v);
                break;
            }
        }
        return;
    }

public:
    vector<int> findPermutation(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        int temp=fn(1,0,nums);
        reconstruct(1,0,nums);
        return ans;
    }
};