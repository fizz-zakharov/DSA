class Solution {
private:
    int gcd(int a,int b){
        while(b){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            long long prod=1,g=0,l=1;
            for(int j=i;j<n;j++){
                prod*=nums[j];
                if(prod>=25200)break;
                g=gcd(nums[j],g);
                l=l/gcd(l,nums[j])*nums[j];
                if(prod==(long long)l*g){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};