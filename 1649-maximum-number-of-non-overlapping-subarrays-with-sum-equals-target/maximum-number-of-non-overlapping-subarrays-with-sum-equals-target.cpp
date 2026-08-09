class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_set<int> s;
        s.insert(0);
        int sum=0;
        int ans=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(s.count(sum-target)){
                ans++;
                s.clear();
                s.insert(0);
                sum=0;
            }
            else s.insert(sum);
        }
        return ans;
    }
};