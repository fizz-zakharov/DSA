class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        map<int,int> m; //{sum,index}
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i])sum++;
            else sum--;
            pre[i]=sum;
            if(pre[i]==0)ans=max(ans,i+1);
            if(m.find(pre[i])!=m.end()){
                ans=max(ans,i-m[pre[i]]);
            }
            else{
                m[pre[i]]=i;
            }
        }
        return ans;
    }
};