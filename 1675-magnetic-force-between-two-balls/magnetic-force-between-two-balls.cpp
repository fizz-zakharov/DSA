class Solution {
private:
    bool valid(int k,vector<int>&v,int m,int n){
        int t=v[0];
        m--;
        for(int i=1;i<n;i++){
            if(v[i]-t>=k){
                m--;
                t=v[i];
            }
            if(m==0)return true;
        }
        if(m<=0)return true;
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int low=0,high=1e9+1;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(valid(mid,position,m,n)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};