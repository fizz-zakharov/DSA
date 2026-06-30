class Solution {
private:
    bool valid(long long x,vector<int>&v,int t){
        long long c=0;
        for(int i=0;i<v.size();i++){
            c+=x/v[i];
            if(c>=t)return true;
        }
        return false;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();
        long long low=0,high=1e18;
        long long ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(valid(mid,time,totalTrips)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};