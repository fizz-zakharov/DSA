class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int j=nums[0];
        for(int i=0;i<n;i++){
            if(j>=n-1)return true;
            if(nums[i]==0 && j<=i)return false;
            j=max(j,i+nums[i]);
        }
        return true;
    }
};