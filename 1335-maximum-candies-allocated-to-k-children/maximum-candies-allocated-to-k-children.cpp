class Solution {
private:
    bool valid(long long m,vector<int>&v,long long k){
        long long ans=0;
        if(m==0)return true;
        for(int i=0;i<v.size();i++){
            ans+=(v[i]/m);
        }
        return (ans>=k);
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        sort(candies.begin(),candies.end());
        long long low=0,high=candies[n-1];
        int ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(valid(mid,candies,k)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};