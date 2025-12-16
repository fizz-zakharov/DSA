class Solution {
private:
    long long fn(long long n){
        if(n==0)return 1;
        if(n==1)return 3;
        long long k=n-2;
        return ((k+1)*(k+2))/2;
    }
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long n=prices.size();
        long long ans=n;
        long long temp=1;
        bool yes=false;
        for(int i=1;i<n;i++){
            if(prices[i-1]-prices[i]==1){
                temp++;
                yes=true;
            }
            else{
                if(yes)ans+=fn(temp);
                yes=false;
                temp=1;
            }
        }
        if(yes)ans+=fn(temp);
        return ans;
    }
};