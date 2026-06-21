class Solution {
private:
    int dp[12][2][2];

    int fn(int i,int tight,int zero,vector<string>&v,string& s){
        if(i>=s.size()){
            if(!zero)return 1;
            return 0;
        }
        if(dp[i][tight][zero]!=-1)return dp[i][tight][zero];
        int a=0;
        if(zero)a+=fn(i+1,0,1,v,s);
        for(int j=0;j<v.size();j++){
            int num=v[j][0]-'0';
            if(tight && num>s[i]-'0')break;
            int newtight=(tight && num==s[i]-'0')?1:0;
            a+=fn(i+1,newtight,0,v,s);
            
        }
        return dp[i][tight][zero] = a;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        return fn(0,1,1,digits,s);
    }
};