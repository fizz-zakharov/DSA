class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        for(int i=1;i<n;i++){
            v.push_back(nums[i]);
        }
        sort(v.begin(),v.end());
        return nums[0]+v[0]+v[1];
    }
};