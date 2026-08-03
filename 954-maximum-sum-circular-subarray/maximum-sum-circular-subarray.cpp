class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int ans=-1e9;
        vector<int> temp;
        int total=0;
        for(int i=0;i<n;i++){
            temp.push_back(-nums[i]);
            total+=nums[i];
        }
        int cur=0;
        int neg=0;
        int minsum=-1e9;
        for(int i=0;i<n;i++){
            cur+=nums[i];
            ans=max(ans,cur);
            if(cur<0)cur=0;

            neg+=temp[i];
            minsum=max(minsum,neg);
            if(neg<0)neg=0;
        }

        minsum*=(-1);
        if(ans<0)return ans;
        ans=max(ans,total-minsum);
        return ans;


    }
};