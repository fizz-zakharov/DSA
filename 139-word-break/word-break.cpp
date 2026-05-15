class Solution {
map<string,int> m;
int dp[301];
private:
    bool fn(int i,string s,int n){
        if(i>=n)return true;
        string temp=s.substr(i,n-i);
        if(m[temp]>0)return dp[i]= true;
        if(dp[i]!=-1)return dp[i];
        for(int l=1;l<=n-i;l++){
            string s1=s.substr(i,l);
            bool check=(m[s1]>0)?true:false;
            if(check&&fn(i+l,s,n))return dp[i]= true;
        }
        return dp[i]= false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        memset(dp, -1, sizeof(dp));
        for(auto it:wordDict){
            m[it]++;
        }
        return fn(0,s,n);
    }
};