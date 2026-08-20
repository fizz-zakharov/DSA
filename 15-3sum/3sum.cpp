class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int temp=1e5+1;
        for(int i=0;i<n;i++){
            if(nums[i]>0)break;
            if(i>0 && nums[i]==nums[i-1])continue;
            int j=i+1,k=n-1;
            while(j<n && k>=0 && j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    int temp1=nums[j];
                    int temp2=nums[k];
                    while(j<n && nums[j]==temp1){
                        j++;
                    }
                    while(k>=0 && nums[k]==temp2){
                        k--;
                    }
                }
                else if(sum<0){
                    j++;
                }
                else k--;
            }
        }
        return ans;
    }
};