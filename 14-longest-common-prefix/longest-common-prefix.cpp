class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans;
        sort(strs.begin(),strs.end());
        for(int i=0;i<strs[0].size();i++){
            char x=strs[0][i];
            for(int j=0;j<n;j++){
                if(strs[j][i]!=x)return ans;
            }
            ans.push_back(x);
        }
        return ans;
    }
};