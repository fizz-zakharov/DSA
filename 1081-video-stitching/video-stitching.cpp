class Solution {
private:
    int dp[102][102];
    int fn(int i,int r,vector<vector<int>>&v,int time){
        if(r>=time){
            return 0;
        }
        if(i>=v.size())return 1e9;
        if(dp[i][r]!=-1)return dp[i][r];
        int start=v[i][0];
        int end=v[i][1];
        int a=1e9,b=1e9;
        if(start<=r){
            a=1+fn(i+1,max(end,r),v,time);
            b=fn(i+1,r,v,time);
        }

        return dp[i][r] = min(a,b);
    }
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n=clips.size();
        sort(clips.begin(),clips.end());
        memset(dp,-1,sizeof(dp));
        int ans=fn(0,0,clips,time);
        if(ans>=1e9)return -1;
        return ans;
    }
};