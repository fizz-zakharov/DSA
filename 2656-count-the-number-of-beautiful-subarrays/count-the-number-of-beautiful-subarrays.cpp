class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_map<long long,long long> m;
        long long ans=0;
        long long x=0;
        m[0]=1;
        for(int i=0;i<n;i++){
            x^=nums[i];
            if(m.find(x)!=m.end()){
                ans+=m[x];
            }
            m[x]++;
        }
        return ans;
    }
};