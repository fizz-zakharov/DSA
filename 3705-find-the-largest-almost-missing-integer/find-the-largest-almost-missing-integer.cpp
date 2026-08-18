class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int ans=-1;
        if(k==n){
            for(auto it:m){
                ans=max(ans,it.first);
            }
            return ans;
        }
        if(k==1){
            for(auto it:m){
                if(it.second==1){
                    ans=max(ans,it.first);
                }
                
            }
            return ans;
        }
        if(m[nums[0]]>1 && m[nums[n-1]]>1)return ans;
        else if(m[nums[0]]>1)return nums[n-1];
        else if(m[nums[n-1]]>1)return nums[0];
        return max(nums[0],nums[n-1]);
    }
};