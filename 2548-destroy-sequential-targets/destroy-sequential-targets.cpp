class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]%space]++;
        }
        int maxf=INT_MIN;
        int num=0;
        for(auto it:m){
            if(it.second>maxf){
                maxf=it.second;
            }
        }
        for(int i=0;i<n;i++){
            if(m[nums[i]%space]==maxf)return nums[i];
        }
        return nums[0];
    }
};