class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        bool s=false;
        int temp=-1;
        int mx=nums[0];
        for(int i=0;i<n;i++){
            if(s && nums[i]>mx)return false;
            if(nums[i]<temp){
                if(!s){
                    s=true;
                }
                else{
                    return false;
                }
            }
            temp=nums[i];
        }
        if(s && nums[n-1]>mx)return false;
        return true;
    }
};