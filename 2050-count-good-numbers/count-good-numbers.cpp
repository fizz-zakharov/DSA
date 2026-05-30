class Solution {
    long long MOD=1e9+7;

    long long power(long long base,long long exp,long long mod){
        long long ans=1;
        base%=mod;
        while(exp>0){
            if(exp&1)ans=(ans*base)%mod;
            base=(base*base)%mod;
            exp>>=1;
        }
        return ans;
    }

public:
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2; 
        long long odd=n/2;      
        long long ans=power(5,even,MOD)*power(4,odd,MOD)%MOD;
        return (int)ans;
    }
};