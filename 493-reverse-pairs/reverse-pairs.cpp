class Solution {
private:
    vector<int> mergesort(vector<int>&v,int l,int r,int& ans){
        if(l==r)return {v[l]};
        int mid=l+(r-l)/2;
        vector<int> a=mergesort(v,l,mid,ans);
        vector<int> b=mergesort(v,mid+1,r,ans);

        int right=0;
        for(int left=0;left<a.size();left++){
            while(right<b.size() && (long long)a[left]>2LL*b[right]){
                right++;
            }
            ans+=right;
        }

        vector<int> res;
        int i=0,j=0;
        while(true){
            if(i<a.size() && j<b.size()){
                if(a[i]<=b[j]){
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
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int> temp=mergesort(nums,0,n-1,ans);
        return ans;
    }
};