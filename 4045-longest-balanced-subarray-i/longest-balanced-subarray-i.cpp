class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            set<int> odd;
            set<int> even;
            int c=0;
            for(int j=i;j<n;j++){
                c++;
                if(nums[j]&1)odd.insert(nums[j]);
                else even.insert(nums[j]);
                if(odd.size()==even.size())ans=max(ans,c);
            }
        }
        return (ans==INT_MIN)?0:ans;
    }
};