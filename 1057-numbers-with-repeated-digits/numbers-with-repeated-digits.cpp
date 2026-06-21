class Solution {
private:
    int dp[12][2][2][1025][2];

    int fn(int i,int tight,int zero,int mask,int found,string& s){
        if(i>=s.size()){
            if(zero==0 && found)return 1;
            return 0;
        }
        if(dp[i][tight][zero][mask][found]!=-1)return dp[i][tight][zero][mask][found];
        int limit=(tight)?s[i]-'0':9;

        int a=0;
        for(int j=0;j<=limit;j++){
            int newtight=(tight && j==limit)?1:0;
            int newmask=mask;
            if(zero){
                if(j!=0){
                    newmask=(mask|(1<<j));
                    a+=fn(i+1,newtight,0,newmask,found,s);
                }
                else{
                    a+=fn(i+1,newtight,1,mask,found,s);
                }
            }
            else{
                if(mask&(1<<j))a+=fn(i+1,newtight,0,newmask,1,s);
                else{
                    newmask=(mask|(1<<j));
                    a+=fn(i+1,newtight,0,newmask,found,s);
                }
            }
        }
        return dp[i][tight][zero][mask][found] = a;
    }
public:
    int numDupDigitsAtMostN(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return fn(0,1,1,0,0,s);
    }
};