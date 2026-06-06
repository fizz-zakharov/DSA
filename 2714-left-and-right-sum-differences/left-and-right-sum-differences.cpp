class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        vector<int> suff(n);
        vector<int> ans(n);
        int sum=0;
        for(int i=0;i<n;i++){
            pre[i]=sum;
            sum+=nums[i];
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            suff[i]=sum;
            sum+=nums[i];
        }
        for(int i=0;i<n;i++){
            ans[i]=abs(pre[i]-suff[i]);
        }
        return ans;

    }
};