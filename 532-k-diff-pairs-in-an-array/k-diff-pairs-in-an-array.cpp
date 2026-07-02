class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int> m;
        set<pair<int,int>> s;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        if(k==0){
            for(auto it:m){
                if(it.second>1)ans++;
            }
            return ans;
        }
        for(int i=0;i<n;i++){
            if(m.find(nums[i]-k)!=m.end()){
                if(s.find({nums[i]-k,nums[i]})==s.end()){
                    ans++;
                    s.insert({nums[i]-k,nums[i]});
                }
            }
            if(m.find(nums[i]+k)!=m.end()){
                if(s.find({nums[i],nums[i]+k})==s.end()){
                    ans++;
                    s.insert({nums[i],nums[i]+k});
                }
            }
        }
        return ans;
    }
};