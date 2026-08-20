class Solution {
private:
    vector<pair<int,int>> mergesort(vector<pair<int,int>>&v,int l,int r,vector<int>& ans){
        if(l==r)return {v[l]};
        int mid=l+(r-l)/2;
        vector<pair<int,int>> a=mergesort(v,l,mid,ans);
        vector<pair<int,int>> b=mergesort(v,mid+1,r,ans);

        for(int i=0;i<a.size();i++){
            auto it=upper_bound(b.begin(),b.end(),a[i]);
            ans[a[i].second]+=it-b.begin();
        }

        vector<pair<int,int>> res;
        int i=0,j=0;
        while(true){
            if(i<a.size() && j<b.size()){
                if(a[i].first<=b[j].first){
                    res.push_back(a[i]);
                    i++;
                }
                else{
                    res.push_back(b[j]);
                    j++;
                }
            }
            else if(i<a.size()){
                res.push_back(a[i]);
                i++;
            }
            else if(j<b.size()){
                res.push_back(b[j]);
                j++;
            }
            else break;
        }
        return res;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)v.push_back({nums[i],i});
        vector<int> ans(n,0);
        vector<pair<int,int>> temp=mergesort(v,0,n-1,ans);
        return ans;

    }
};