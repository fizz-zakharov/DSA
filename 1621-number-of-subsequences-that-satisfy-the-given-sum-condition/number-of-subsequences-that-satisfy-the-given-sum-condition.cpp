class Solution {
private:
    long long MOD=1e9+7;
    long long binexp(int a,int x){
        if(x==1)return a;
        if(x==0)return 1;
        long long ans=binexp(a,x/2);
        ans=(ans*ans)%MOD;
        if(x&1)ans=(ans*a)%MOD;
        return ans%MOD;
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=target)continue;
            auto it=upper_bound(nums.begin(),nums.end(),target-nums[i]);
            int ind=it-nums.begin()-1;
            if(ind<=i)continue;
            int rem=ind-i-1;
            ans=(ans+binexp(2,rem+1)-1)%MOD;
        }
        for(int i=0;i<n;i++){
            if(nums[i]+nums[i]<=target)ans++;
        }
        return ans;
    }
};