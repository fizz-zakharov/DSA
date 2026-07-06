class Solution {
public:
    int countPrimes(int n) {
        int prime[n+1];
        memset(prime,1,sizeof(prime));

        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=0;
                }
            }
        }
        int ans=0;
        for(int i=2;i<n;i++){
            if(prime[i])ans++;
        }
        return ans;
    }
};