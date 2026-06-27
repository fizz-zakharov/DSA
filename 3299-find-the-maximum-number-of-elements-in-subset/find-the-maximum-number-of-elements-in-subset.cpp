class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=1;
        unordered_map<long long,int> m;
        for(int i=0;i<n;i++)m[nums[i]]++;
        
        if(m.find(1)!=m.end()){
            if(m[1]%2==0){
                ans=max(ans,m[1]-1);
            }
            else ans=max(ans,m[1]);
        }

        for(int i=0;i<n;i++){
            if(nums[i]==1)continue;
            if(m[nums[i]]!=-1){
                long long cur=nums[i];
                int c=1;
                while(cur){
                    ans=max(ans,2*c-1);
                    if(m[cur]>1 && m.find(cur*cur)!=m.end() && cur*cur!=cur){
                        m[cur]=-1;
                        cur=cur*cur;
                        c++;
                    }
                    else break;
                }
                ans=max(ans,2*c-1);
            }
        }
        return ans;
    }
};