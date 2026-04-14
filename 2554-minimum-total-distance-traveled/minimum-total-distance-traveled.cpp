class Solution {
private:
    long long fn(int i,int j,vector<int>&r,vector<int>&f,vector<vector<long long>>&dp){
        int n=r.size();
        int m=f.size();
        if(i>=n||j>=m){
            if(i>=n)return 0;
            return 1e15;
        }
        if(dp[i][j]!=-1)return dp[i][j];

        long long a=1e15;
        //take
        a=abs(r[i]-f[j]) + fn(i+1,j+1,r,f,dp);

        //skip
        long long b=1e15;
        b=fn(i,j+1,r,f,dp);

        return dp[i][j] = min(a,b);
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n=robot.size();
        int m=factory.size();
        sort(robot.begin(),robot.end());
        vector<int> v;
        for(int i=0;i<m;i++){
            int k=factory[i][1];
            while(k--)v.push_back(factory[i][0]);
        }
        sort(v.begin(),v.end());
        int sz=v.size();
        vector<vector<long long>> dp(n,vector<long long>(sz,-1));
        return fn(0,0,robot,v,dp);
        
    }
};