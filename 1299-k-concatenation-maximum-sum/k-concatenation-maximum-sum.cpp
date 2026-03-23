class Solution {
long long MOD=1e9+7;
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long n=arr.size();
        long long ans=0;
        long long sum=0;
        for(long long i=0;i<n;i++){
            sum+=arr[i];
            ans=max(ans,sum);
            if(sum<0)sum=0;
        }
        long long arrsum=0;
        for(auto it:arr)arrsum+=it;
        ans=max(ans,arrsum*k);

        vector<long long> pre(n,0);
        vector<long long> suff(n,0);

        long long s=0;
        for(long long i=0;i<n;i++){
            s+=arr[i];
            pre[i]=s;
        }
        s=0;
        for(long long i=n-1;i>=0;i--){
            s+=arr[i];
            suff[i]=s;
        }
        long long maxpre=0,maxsuff=0;
        for(long long i=0;i<n;i++)maxpre=max(maxpre,pre[i]);
        for(long long i=n-1;i>=0;i--)maxsuff=max(maxsuff,suff[i]);
        long long ps=(k>1)?maxpre+maxsuff:0;
        ans=max(ans,ps)%MOD;

        if (k > 2 && arrsum > 0) {
            long long mid = maxsuff + (k - 2) * arrsum + maxpre;
            ans = max(ans, mid);
        }
        return ans%MOD;

    }
};