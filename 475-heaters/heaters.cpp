class Solution {
private:
    bool valid(int k,vector<int>&v,vector<int>&w){
        int n=v.size();
        int m=w.size();
        if(v[0]<w[0]-k||v[n-1]>w[m-1]+k)return false;
        for(int i=1;i<m;i++){
            if(w[i-1]+k<w[i]-k){
                auto it=lower_bound(v.begin(),v.end(),w[i-1]+k+1);
                int ind=it-v.begin();
                if(ind>=v.size())return true;
                else{
                    if(v[ind]>w[i-1]+k&&v[ind]<w[i]-k)return false;
                }
            }
        }
        return true;
    }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n=houses.size();
        int m=heaters.size();
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());

        int low=0,high=1e9;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(valid(mid,houses,heaters)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};