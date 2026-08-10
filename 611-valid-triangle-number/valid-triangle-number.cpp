class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return 0;
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                auto it=lower_bound(nums.begin(),nums.end(),nums[i]+nums[j]);
                int ind=-1;
                if(it==nums.end()){
                    ind=n-1;
                    if(nums[i]+nums[j]>nums[ind] && nums[i]+nums[ind]>nums[j] && nums[j]+nums[ind]>nums[i] && j!=ind){
                        //cout<<i<<" "<<j<<" "<<ind<<'\n';
                        ans+=max(0,ind-j);
                    }
                }
                else{
                    ind=it-nums.begin()-1;
                    //cout<<nums[i]<<" "<<nums[j]<<" "<<ind<<'\n';
                    ans+=max(0,ind-j);
                }
                
            }
        }
        return ans;
    }
};