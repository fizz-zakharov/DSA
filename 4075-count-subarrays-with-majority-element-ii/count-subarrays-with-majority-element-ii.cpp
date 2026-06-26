class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> m;
        int cur=0;
        long long ans=0;
        long long left=0;
        m[0]=1;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                left+=m[cur];
                cur++;
            }
            else{
                cur--;
                left-=m[cur];
            }
            m[cur]++;
            ans+=left;
        }
        return ans;
    }
};