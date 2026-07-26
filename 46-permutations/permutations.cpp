class Solution {
private:
    void fn(int i,vector<int>&v,vector<int>&temp,vector<vector<int>>&ans){
        if(i==v.size()){
            ans.push_back(temp);
        }
        for(int j=0;j<v.size();j++){
            if(v[j]==100)continue;
            int x=v[j];
            temp.push_back(x);
            v[j]=100;
            fn(i+1,v,temp,ans);
            v[j]=x;
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        fn(0,nums,temp,ans);
        return ans;
    }
};