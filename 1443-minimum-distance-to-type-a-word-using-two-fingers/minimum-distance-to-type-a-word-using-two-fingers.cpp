class Solution {
int fn(int i,char pl,char pr,map<char,pair<int,int>>&m,string s,vector<vector<vector<int>>>&dp){
    int n=s.size();
    if(i>=n)return 0;
    int l=pl-'A';
    int r=pr-'A';
    if(dp[i][l][r]!=-1)return dp[i][l][r];
    
    int xl=m[pl].first;
    int yl=m[pl].second;
    int xr=m[pr].first;
    int yr=m[pr].second;

    int x=m[s[i]].first;
    int y=m[s[i]].second;
    //use left key
    int a=INT_MAX;
    if(pl!='[')a=abs(xl-x)+abs(yl-y)+fn(i+1,s[i],pr,m,s,dp);
    else a=fn(i+1,s[i],pr,m,s,dp);
    
    //use right key
    int b=INT_MAX;
    if(pr!='[')b=abs(xr-x)+abs(yr-y)+fn(i+1,pl,s[i],m,s,dp);
    else b=fn(i+1,pl,s[i],m,s,dp);

    return dp[i][l][r]= min(a,b);
}
public:
    int minimumDistance(string word) {
        int n=word.size();
        map<char,pair<int,int>> m;
        int i=0,j=0;
        char ch='A';
        while(i<5){
            if(j==6){
                j=0;
                i++;
            }
            m[ch]=make_pair(i,j);
            j++;
            if(ch=='Z')break;
            ch++;
        }
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(28,vector<int>(28,-1)));
        int ans=fn(0,'[','[',m,word,dp);
        if(ans==INT_MAX)return -1;
        return ans;
    }
};