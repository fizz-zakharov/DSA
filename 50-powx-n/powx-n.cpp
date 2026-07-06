class Solution {
private:
    double binaryexp(double x,long long n){
        if(n==0)return 1;
        double ans=1;
        if(n&1){
            ans=ans*x;
            n--;
        }
        return ans*binaryexp(x*x,n/2);
    }
public:
    double myPow(double x, int n) {
        long long t=n;
        if(n<0)return binaryexp(1/x,-t);
        return binaryexp(x,t);
    }
};