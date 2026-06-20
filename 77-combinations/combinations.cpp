class Solution {
private:
    void fn(int start,int k,vector<int>& v,vector<vector<int>>& ans,int n){
        if(k==0){
            ans.push_back(v);
            return;
        }
        for(int i=start;i<=n;i++){
            v.push_back(i);
            fn(i+1,k-1,v,ans,n);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        vector<vector<int>> ans;
        fn(1,k,v,ans,n);
        return ans;
    }
};