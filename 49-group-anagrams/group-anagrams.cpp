class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        map<string,vector<string>> m;
        for(int i=0;i<n;i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            m[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;


    }
};