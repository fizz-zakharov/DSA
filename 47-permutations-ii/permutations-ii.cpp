class Solution {
private:
    void fn(int i,vector<int>&v,vector<int>&temp,set<vector<int>>&s){
        if(i==v.size()){
            s.insert(temp);
        }
        for(int j=0;j<v.size();j++){
            if(v[j]==100)continue;
            int x=v[j];
            temp.push_back(x);
            v[j]=100;
            fn(i+1,v,temp,s);
            v[j]=x;
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        set<vector<int>> s;
        fn(0,nums,temp,s);
        vector<vector<int>> ans;
        for(auto it:s)ans.push_back(it);
        return ans;
    }
};