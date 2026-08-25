class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int c=2;
        int cur=k;
        for(int i=0;i<n;i++){
            if(nums[i]==cur){
                cur=k*c;
                c++;
            }
        }
        return cur;
    }
};