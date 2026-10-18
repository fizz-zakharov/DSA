class Solution {
private:
    static int digsum(int n){
        int temp=n;
        int sum=0;
        while(temp){
            sum+=temp%10;
            temp/=10;
        }
        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> sortednums=nums;
        sort(sortednums.begin(),sortednums.end(),[](const int a,const int b){
            int sum1=digsum(a);
            int sum2=digsum(b);
            if(sum1!=sum2)return sum1<sum2;
            return a<b;
        });
        unordered_map<int,int> ind;
        for(int i=0;i<n;i++){
            ind[sortednums[i]]=i;
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i] || ind[nums[i]]==i)continue;
            int cycle_len=0;
            int cur=i;
            while(vis[cur]==0){
                vis[cur]=1;
                cur=ind[nums[cur]];
                cycle_len++;
            }
            if(cycle_len>1)ans+=cycle_len-1;
        }
        return ans;
    }
};