class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        if(n==1)return nums[0]+1;
        int sum=0;
        int ans=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)m[nums[i]]++;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            pre[i]=sum;
            //cout<<pre[i]<<'\n';
            if(i>0 && nums[i]!=nums[i-1]+1){
                if(m.find(pre[i-1])==m.end())return pre[i-1];
                int temp=pre[i-1];
                while(m.find(temp)!=m.end()){
                    //cout<<temp<<'\n';
                    temp++;
                }
                return temp;
            }
        }
        return pre[n-1];
    }
};