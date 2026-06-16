class Solution {
public:
    string processStr(string s) {
        int n=s.size();
        string ans;
        for(int i=0;i<n;i++){
            if(ans.size()!=0 && s[i]=='*')ans.pop_back();
            if(ans.size()!=0 && s[i]=='#')ans+=ans;
            if(ans.size()!=0 && s[i]=='%')reverse(ans.begin(),ans.end());
            if(s[i]!='*'&&s[i]!='#'&&s[i]!='%')ans.push_back(s[i]);
        }
        return ans;
    }
};