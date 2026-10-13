class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n=nums.size();
        long long MOD=1e9+7;
        if(n==1){
            return (nums[0]*nums[0])%MOD;
        }
        vector<vector<int>> bits(n,vector<int>(35,0));
        priority_queue<long long> pq;
        for(int i=0;i<n;i++){
            int temp=nums[i];
            int j=0;
            while(temp){
                if(temp&1){
                    bits[i][j]++;
                }
                j++;
                temp=(temp>>1);
            }
        }
        int mx=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<35;j++){
                bits[i][j]+=bits[i-1][j];
                mx=max(mx,bits[i][j]);
            }
        }
        while(mx--){
            long long temp=0;
            for(int i=0;i<35;i++){
                if(bits[n-1][i]){
                    temp+=(1LL<<i);
                    bits[n-1][i]--;
                }
            }
            pq.push(temp);
        }
        long long ans=0;
        while(k--){
            if(pq.empty())break;
            long long val=pq.top();
            ans=(ans+(val*val)%MOD)%MOD;
            pq.pop();
        }
        return ans;

    }
};