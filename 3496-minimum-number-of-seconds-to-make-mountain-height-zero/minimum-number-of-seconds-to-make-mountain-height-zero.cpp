class Solution {
private:
    bool valid(long long k,vector<int>&v,int h){
        long long c=0;
        for(auto w:v){
            long long val=8*(k/w);
            long long x=(sqrt(1+val)-1)/2;
            c+=x;
        }
        if(c>=h)return true;
        return false;
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long h=mountainHeight;
        int n=workerTimes.size();
        sort(workerTimes.begin(),workerTimes.end());
        long long low=0;
        long long high=1LL*workerTimes[0]*(((h)*(h+1))/2);

        long long ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(valid(mid,workerTimes,h)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};