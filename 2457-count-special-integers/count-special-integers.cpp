class Solution {
private:
    int fn(int i,int tight,int mask,string& s,vector<vector<vector<int>>>&dp){
        if(i>=s.size()){
            return 1;
        }
        if(dp[i][tight][mask]!=-1)return dp[i][tight][mask];
        int ans=0;
        if(tight==1){
            for(int j=0;j<=s[i]-'0';j++){
                if(mask&(1<<j))continue;
                int newmask=mask;
                if(j==0 && mask==0){
                    newmask=mask;
                }
                else{
                    newmask=mask|(1<<j);
                }
                int newtight=0;
                if(j==s[i]-'0')newtight=1;
                ans+=fn(i+1,newtight,newmask,s,dp);
            }
        }
        else{
            for(int j=0;j<=9;j++){
                if(mask&(1<<j))continue;
                int newmask=mask;
                if(j==0 && mask==0){
                    newmask=mask;
                }
                else{
                    newmask=mask|(1<<j);
                }
                ans+=fn(i+1,0,newmask,s,dp);
            }
        }
        return dp[i][tight][mask]= ans;
    }
public:
    int countSpecialNumbers(int n) {
        string s=to_string(n);
        vector<vector<vector<int>>> dp(s.size(),vector<vector<int>>(2,vector<int>(1024,-1)));
        return fn(0,1,0,s,dp)-1;
    }
};