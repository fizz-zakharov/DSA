class Solution {
const vector<char> color={'a','b','c'};
long long MOD=1e9+7;
vector<vector<long long>> dp;

private:
    long long fn(int i,int prev,int n,vector<string>&v){
        if(i>=n) return 1;                         
        if(dp[i][prev+1]!=-1)return dp[i][prev+1]; 

        long long ans=0;
        for(int j=0;j<v.size();j++){
            if(prev==-1)ans=(ans+fn(i+1,j,n,v))%MOD;
            else{
                // check no same color in same row of adjacent columns
                bool ok=true;
                for(int k=0;k<v[0].size();k++){
                    if(v[j][k]==v[prev][k]){
                        ok=false;
                        break;
                    }
                }
                if(ok)ans=(ans+fn(i+1,j,n,v))%MOD;
            }
        }
        return dp[i][prev+1]=ans;
    }

public:
    int colorTheGrid(int m, int n) {
        vector<string> patterns;
        queue<string> q;
        q.push("");
        while(!q.empty()){
            string cur=q.front();               
            q.pop();
            if(cur.size()==m){
                patterns.push_back(cur);
                continue;
            }
            for(int i=0;i<3;i++){
                if(cur.empty()||cur[cur.size()-1]!=color[i]){
                    string newstr=cur;
                    newstr.push_back(color[i]);
                    q.push(newstr);
                }
            }
        }
        int sz=patterns.size();
        dp.assign(n,vector<long long>(sz+1,-1));
        return (int)fn(0,-1,n,patterns);
    }
};