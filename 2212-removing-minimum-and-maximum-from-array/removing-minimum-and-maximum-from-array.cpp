class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
        }
        int ans1=0,ans2=0,ans3=0;
        int c=0;
        int l=-1,r=-1;
        for(int i=0;i<n;i++){
            ans1++;
            if(nums[i]==mn || nums[i]==mx){
                if(l==-1)l=ans1;
            }
            if(nums[i]==mn)c++;
            if(nums[i]==mx)c++;
            if(c==2)break;
        }
        c=0;
        for(int i=0;i<n;i++){
            ans2++;
            if(nums[n-i-1]==mn || nums[n-i-1]==mx){
                if(r==-1)r=ans2;
            }
            if(nums[n-i-1]==mn)c++;
            if(nums[n-i-1]==mx)c++;
            if(c==2)break;
        }
        ans3=l+r;
        return min({ans1,ans2,ans3});
    }
};