class Solution {
public:
    long long sumAndMultiply(int n) {
        int  temp=n;
        long long ans=0;
        int sum=0;
        long long t=1;
        while(temp){
            int x=temp%10;
            if(x!=0){
                ans=t*x+ans;
                t=t*10;
                sum+=x;
            }
            temp=temp/10;
        }
        ans=ans*(long long)sum;
        return ans;
    }
};