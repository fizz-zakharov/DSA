class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        int c=0;
        int ct=0;
        for(int i=0;i<n;i++){
            if(seq[i]=='(')c++;
            else c--;
            ct=max(ct,c);
        }
        c=0;
        vector<int> ans(n,0);
        int h=(ct&1)?ct/2+1:ct/2;
        for(int i=0;i<n;i++){
            if(c<=h && seq[i]==')')ans[i]=1;
            if(seq[i]=='(')c++;
            else c--;
            if(c<=h && seq[i]=='(')ans[i]=1;
        }
        return ans;
    }
};