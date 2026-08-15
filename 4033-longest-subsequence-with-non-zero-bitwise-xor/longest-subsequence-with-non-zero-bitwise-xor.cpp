class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        int c=0;
        for(int i=0;i<n;i++){
            x^=nums[i];
            if(nums[i]==0)c++;
        }
        if(c==n)return 0;
        if(x!=0)return n;
        return n-1;
    }
};