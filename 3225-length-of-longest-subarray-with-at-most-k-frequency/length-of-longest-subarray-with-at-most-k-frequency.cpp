class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MIN;
        int j=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            while(m[nums[i]]>k){
                m[nums[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};