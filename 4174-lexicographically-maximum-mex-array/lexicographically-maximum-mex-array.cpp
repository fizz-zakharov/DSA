class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n=nums.size();
        map<int,int> m;
        for(int i=0;i<n;i++)m[nums[i]]++;
        int mex=0;
        while(m[mex])mex++;
        set<int> s;
        int left_mex=0;
        int right_mex=mex;
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
            while(s.count(left_mex))left_mex++;
            m[nums[i]]--;
            if(m[nums[i]]==0)right_mex=min(right_mex,nums[i]);
            if(left_mex==mex){
                ans.push_back(left_mex);
                left_mex=0;
                s.clear();
                mex=right_mex;
            }
        }
        return ans;
    }
};