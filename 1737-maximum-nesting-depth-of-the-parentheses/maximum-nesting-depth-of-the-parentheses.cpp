class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')sum++;
            if(s[i]==')')sum--;
            ans=max(ans,sum);
        }
        return ans;
    }
};