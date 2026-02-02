class Solution {
private:
    bool valid(long long k,vector<int>&v){
        int n=v.size();
        long long c=0;
        for(int i=0;i<n;i++){
            if(v[i]%k==0)c+=v[i]/k;
            else c+=v[i]/k + 1;
        }
        long long temp=k*k;
        if(c<=temp)return true;
        return false;
    }
public:
    int minimumK(vector<int>& nums) {
        long long n=nums.size();
        sort(nums.begin(),nums.end());
        long long low=1,high=1e5;
        long long ans=nums[n-1];
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(valid(mid,nums)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};