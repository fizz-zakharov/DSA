class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int cur=nums[0];
        for(int i=1;i<n;i++){
            cur++;
            while(cur!=nums[i]){
                ans.push_back(cur);
                cur++;
            }
        }
        return ans;
    }
};