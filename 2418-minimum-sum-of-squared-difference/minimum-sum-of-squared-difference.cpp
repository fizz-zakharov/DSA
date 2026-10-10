class Solution {
private:
    int n;
    vector<long long> v;
    long long k;
    long long low=0,high=0;
    long long ans=0;

    bool valid(int mid){
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=(v[i]>mid)?v[i]-mid:0;
        }
        return sum<=k;
    }

public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        n=nums1.size();
        k=k1+k2;
        for(int i=0;i<n;i++){
            v.push_back(abs(nums1[i]-nums2[i]));
            high=max(high,v[i]);
        }
        int res=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(valid(mid)){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        for(int i=0;i<n;i++){
            if(v[i]>res){
                k-=(v[i]-res);
            }
        }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<n;i++){
            long long diff=(res>=v[i])?v[i]:res;
            if(k && diff){
                diff--;
                k--;
            }
            ans+=diff*diff;
        }
        return ans;

    }
};