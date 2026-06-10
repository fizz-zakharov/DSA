class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long ans=((long long)(nums[n-1]-nums[0]))*k;
        return ans;
    }
};