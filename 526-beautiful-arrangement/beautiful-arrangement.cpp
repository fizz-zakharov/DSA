class Solution {
private:
    int fn(int i,int mask,int n){
        if(i>n)return 1;

        int newmask=mask;
        int ans=0;
        for(int j=1;j<=n;j++){
            if(mask&(1<<j))continue;
            if(i%j==0 || j%i==0){
                newmask=(mask|(1<<j));
                ans+=fn(i+1,newmask,n);
            }
        }
        return ans;
    }
public:
    int countArrangement(int n) {
        return fn(1,0,n);
    }
};