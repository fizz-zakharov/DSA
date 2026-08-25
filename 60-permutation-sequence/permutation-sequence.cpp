class Solution {
private:
    int factorial(int n){
        if(n==0)return 1;
        if(n==1)return 1;
        return n * factorial(n-1);
    }
public:
    string getPermutation(int n, int k) {
        int mask=0;
        string ans;
        int rem=n-1;
        k--;
        while(rem){
            int fact=factorial(rem);
            int c= k/fact;
            k%=fact;
            for(int i=1;i<=n;i++){
                if(mask&(1<<i))continue;
                if(c==0){
                    mask=mask|(1<<i);
                    ans.push_back(i+'0');
                    break;
                }
                c--;
            }
            rem--;
        }
        for(int i=1;i<=n;i++){
            if(mask&(1<<i))continue;
            else{
                ans.push_back(i+'0');
                break;
            }
        }
        return ans;
    }
};