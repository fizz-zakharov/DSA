class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        unordered_map<int,int> m;
        set<int> s;
        int i=0,j=0;
        s.insert(nums[i]);
        int ans=INT_MIN;
        while(j<n){
            s.insert(nums[j]);
            m[nums[j]]++;
            int mn=*s.begin();
            int mx=*s.rbegin();
            while(mx-mn>limit){
                m[nums[i]]--;
                if(m[nums[i]]==0){
                    s.erase(nums[i]);
                }
                i++;
                mn=*s.begin();
                mx=*s.rbegin();
            }
            ans=max(ans,j-i+1);
            j++;

        }
        return ans;
    }
};