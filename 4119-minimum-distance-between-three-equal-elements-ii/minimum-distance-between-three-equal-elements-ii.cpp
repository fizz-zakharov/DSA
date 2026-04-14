class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> v(n+1);
        for(int i=0;i<n;i++){
            v[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(int i=0;i<=n;i++){
            if(v[i].size()>=3){
                int p=0,j=1,k=2;
                int dist=0;
                while(k<v[i].size()){
                    dist=(abs(v[i][p]-v[i][j])+abs(v[i][j]-v[i][k])+abs(v[i][k]-v[i][p]));
                    ans=min(dist,ans);
                    p++;
                    j++;
                    k++;
                }
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};