class Solution {
long long MOD=1e9+7;
private:
    int dp[202][3][202];

    int fn(int i,int state,int last,vector<int>&v,string& s){
        if(i>=s.size()){
            if(state==0){
                int low=0,high=last;
                for(int j=low;j<high;j++){
                    if(v[j]!=1)return 1;
                }
                return 0;
            }
            else{
                int low=last+1,high=s.size()+1;
                for(int j=low;j<high;j++){
                    if(v[j]!=1)return 1;
                }
                return 0;
            }
        }
        if(dp[i][state+1][last+1]!=-1)return dp[i][state+1][last+1];
        int newstate=(s[i]=='D')?0:1;
        int a=0;
        if(state==0){
            for(int j=0;j<last;j++){
                if(v[j]!=1){
                    v[j]=1;
                    a=(a+fn(i+1,newstate,j,v,s))%MOD;
                    v[j]=0;
                }
            }
        }
        else if(state==1){
            for(int j=last+1;j<=s.size();j++){
                if(v[j]!=1){
                    v[j]=1;
                    a=(a+fn(i+1,newstate,j,v,s))%MOD;
                    v[j]=0;
                }
            }
        }
        else{
            for(int j=0;j<=s.size();j++){
                v[j]=1;
                a=(a+fn(i+1,newstate,j,v,s))%MOD;
                v[j]=0;
            }
        }
        return dp[i][state+1][last+1] = a;
    }
public:
    int numPermsDISequence(string s) {
        int n=s.size();
        vector<int> v(n+1,0);
        memset(dp,-1,sizeof(dp));
        return fn(0,-1,-1,v,s);
    }
};