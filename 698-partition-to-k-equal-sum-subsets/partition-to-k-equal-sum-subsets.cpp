class Solution {
private:
    int n;
    int val=0;
    int dp[(1<<16)+2];
    bool fn(int i,int mask,int sum,int k,vector<int>&v){
        if(k==0)return true;
        if(sum==val)return fn(0,mask,0,k-1,v);
        if(dp[mask]!=-1)return dp[mask];
        bool ans=false;
        for(int j=i;j<n;j++){
            if(mask&(1<<j))continue;
            if(sum+v[j]>val)continue;
            int newmask=mask|(1<<j);
            ans=ans||(fn(i+1,newmask,sum+v[j],k,v));
        }
        return dp[mask] = ans;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n=nums.size();
        int s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
        }
        if(s%k!=0)return false;
        val=s/k;
        memset(dp,-1,sizeof(dp));
        return fn(0,0,0,k,nums);
    }
};