class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=k-1;
        int t=INT_MAX;
        while(j<n){
            t=min(t,nums[j]-nums[i]);
            i++;
            j++;
        }
        return t;
    }
};