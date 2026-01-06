class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int> m;
        vector<int> suff(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            if(m[nums[i]]>1){
                count++;
            }
            suff[i]=count;
        }

        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int add=nums[i]+(n-1);
            int r=i;
            auto it=upper_bound(nums.begin(),nums.end(),add);
            r+=n-(it-nums.begin());
            int rind=it-nums.begin();
            r+=suff[rind-1]-suff[i];
            ans=min(ans,r);
        }

        return ans;
        
    }
};