class Solution {
private:
    bool valid(int t,vector<int>&v,int n,int k){
        int count=1;
        int cur=v[0];
        for(int i=1;i<n;i++){
            if(count==k)break;
            if(v[i]-cur>=t){
                count++;
                cur=v[i];
            }
        }
        if(count>=k)return true;
        return false;
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n=price.size();
        sort(price.begin(),price.end());
        int low=0,high=1e9;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(valid(mid,price,n,k)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};