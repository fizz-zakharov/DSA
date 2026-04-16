class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        vector<vector<int>> v(*max_element(nums.begin(), nums.end()) + 1);
        for(int i=0;i<n;i++){
            v[nums[i]].push_back(i);
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int q=queries[i];
            int m=v[nums[q]].size();
            if(m==1){
                ans.push_back(-1);
                continue;
            }
            if(q==v[nums[q]][0]){
                int k=min(v[nums[q]][1]-v[nums[q]][0],v[nums[q]][0]+n-v[nums[q]][m-1]);
                ans.push_back(k);
            }
            else if(q==v[nums[q]][m-1]){
                int k=min(v[nums[q]][m-1]-v[nums[q]][m-2],n-v[nums[q]][m-1]+v[nums[q]][0]);
                ans.push_back(k);
            }
            else{
                auto it=lower_bound(v[nums[q]].begin(),v[nums[q]].end(),q);
                int ind=it-v[nums[q]].begin();
                int k=min(v[nums[q]][ind]-v[nums[q]][ind-1],v[nums[q]][ind+1]-v[nums[q]][ind]);
                ans.push_back(k);
            }
        }
        return ans;
    }

};