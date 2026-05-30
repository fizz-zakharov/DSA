class Solution {
private:
    int fn(int k,vector<int>&v){
        int c=0;
        for(int i=0;i<v.size();i++){
            if(v[i]<=k)c++;
        }
        return c;
    }
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=1,high=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(fn(mid,nums)>mid){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};