class Solution {
private:
    int fn(int i,int j,vector<int>&v){
        if(i>j)return 0;
        if(i==j)return v[i];
        int a=v[i]+min(fn(i+2,j,v),fn(i+1,j-1,v));
        int b=v[j]+min(fn(i+1,j-1,v),fn(i,j-2,v));
        return max(a,b);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        int score=fn(0,n-1,nums);
        return score>=(sum-score);
    }
};