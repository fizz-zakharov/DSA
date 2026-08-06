class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0]=1;
        int i2=0,i3=0,i5=0;
        for(int i=1;i<n;i++){
            int u2=dp[i2]*2;
            int u3=dp[i3]*3;
            int u5=dp[i5]*5;

            int next_ugly=min({u2,u3,u5});
            dp[i]=next_ugly;
            if(next_ugly==u2)i2++;
            if(next_ugly==u3)i3++;
            if(next_ugly==u5)i5++;
        }
        return dp[n-1];
    }
};