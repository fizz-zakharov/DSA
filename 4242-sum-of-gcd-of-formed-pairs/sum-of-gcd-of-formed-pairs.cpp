class Solution {
private:
    long long gcd(long long a,long long b){
        while(b!=0){
            long long temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixgcd(n,0);
        int pre=0;
        for(int i=0;i<n;i++){
            pre=max(pre,nums[i]);
            prefixgcd[i]=pre;
        }
        for(int i=0;i<n;i++){
            prefixgcd[i]=gcd(prefixgcd[i],nums[i]);
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        long long ans=0;
        for(int i=0;i<n/2;i++){
            ans+=gcd(prefixgcd[i],prefixgcd[n-i-1]);
        }
        return ans;
        
    }
};