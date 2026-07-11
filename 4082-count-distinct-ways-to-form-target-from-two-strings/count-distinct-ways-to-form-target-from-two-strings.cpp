class Solution {
private:
    int dp[102][102][102][2][2];
    long long MOD=1e9+7;
    int fn(int i,int j,int k,int c1,int c2,string& w1, string& w2, string& target){
        if(k==target.size()){
            if(c1==1 && c2==1){
                return 1;
            }
            return 0;
        }
        if(dp[i][j][k][c1][c2]!=-1)return dp[i][j][k][c1][c2];
        int a=0,b=0;
        for(int ind=i;ind<w1.size();ind++){
            if(w1[ind]==target[k]){
                a=(a+fn(ind+1,j,k+1,1,c2,w1,w2,target))%MOD;
            }
        }
        for(int ind=j;ind<w2.size();ind++){
            if(w2[ind]==target[k]){
                b=(b+fn(i,ind+1,k+1,c1,1,w1,w2,target))%MOD;
            }
        }
        return dp[i][j][k][c1][c2] = (a+b)%MOD;
        
    }
public:
    int interleaveCharacters(string word1, string word2, string target) {
        int m=word1.size();
        int n=word2.size();
        int o=target.size();
        memset(dp,-1,sizeof(dp));
        return fn(0,0,0,0,0,word1,word2,target);
    }
};