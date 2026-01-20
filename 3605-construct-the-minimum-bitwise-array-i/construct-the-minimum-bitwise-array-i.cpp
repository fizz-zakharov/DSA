class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            if(nums[i]==2)v.push_back(-1);
            else{
                for(int j=0;j<=nums[i];j++){
                    if((j|j+1)==nums[i]){
                        v.push_back(j);
                        break;
                    }
                }
            }
        }
        return v;
    }
};