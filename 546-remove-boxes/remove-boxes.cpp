class Solution {
private:
    int fn(int i,int j,int k,vector<int>&v,vector<vector<vector<int>>>&dp){
        if(i>j)return 0;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int x=i;
        int init_k=k;
        while(x<=j && v[i]==v[x]){
            k++;
            x++;
        }
        int a=k*k+fn(x,j,0,v,dp);
        int b=INT_MIN;
        for(int y=x;y<=j;y++){
            if(v[y]==v[i]){
                b=max(b,fn(x,y-1,0,v,dp)+fn(y,j,k,v,dp));
            }
        }
        return dp[i][j][init_k] = max(a,b);
    }
public:
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n+1,-1)));
        return fn(0,n-1,0,boxes,dp);
    }
};