class Solution {
long long MOD=1e9+7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();

        for(auto it:queries){
            int l=it[0];
            int r=it[1];
            int k=it[2];
            int v=it[3];
            while(l<=r){
                nums[l]=(long long)((long long)nums[l]*(long long)v)%MOD;
                l+=k;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=(ans^nums[i]);
        }
        return ans;
    }
};