class Solution {
private:
    long long MOD=1e9+7;
    int dp1[102][102];
    int maxsum(int i,int j,vector<string>&v){
        if(i==0 && j==0){
            return 0;
        }
        if(dp1[i][j]!=-1)return dp1[i][j];
        int a=INT_MIN,b=INT_MIN,c=INT_MIN;
        int cur=(v[i][j]=='S')?0:v[i][j]-'0';
        if(i-1>=0 && v[i-1][j]!='X'){
            int res=maxsum(i-1,j,v);
            if(res!=INT_MIN)a=(cur+res)%MOD;
        }
        if(j-1>=0 && v[i][j-1]!='X'){
            int res=maxsum(i,j-1,v);
            if(res!=INT_MIN)b=(cur+res)%MOD;
        }
        if(i-1>=0 && j-1>=0 && v[i-1][j-1]!='X'){
            int res=maxsum(i-1,j-1,v);
            if(res!=INT_MIN)c=(cur+res)%MOD;
        }
        return dp1[i][j] = max({a,b,c});
    }

    int paths(int i,int j,int s,vector<string>&v,vector<vector<vector<int>>>&dp){
        if(i==0 && j==0){
            if(s==0)return 1;
            return 0;
        }
        if(dp[i][j][s]!=-1)return dp[i][j][s];
        int a=0;
        int cur=(v[i][j]=='S')?0:v[i][j]-'0';
        if(i-1>=0 && v[i-1][j]!='X'){
            a=(a+paths(i-1,j,s-cur,v,dp))%MOD;
        }
        if(j-1>=0 && v[i][j-1]!='X'){
            a=(a+paths(i,j-1,s-cur,v,dp))%MOD;
        }
        if(i-1>=0 && j-1>=0 && v[i-1][j-1]!='X'){
            a=(a+paths(i-1,j-1,s-cur,v,dp))%MOD;
        }
        return dp[i][j][s] = a;
    }


public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        memset(dp1,-1,sizeof(dp1));
        int sum=maxsum(n-1,n-1,board);
        if(sum<0)return {0,0};
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(sum+1,-1)));
        int path=paths(n-1,n-1,sum,board,dp);
        return {sum,path};
    }
};