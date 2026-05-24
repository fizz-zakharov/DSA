class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        map<char,int> m;
        for(int i=0;i<n;i++)m[s[i]]=i;
        int i=0,j=-1;
        vector<int> ans;
        int c=0;
        while(i<n){
            c++;
            j=max(j,m[s[i]]);
            if(i==j){
                ans.push_back(c);
                c=0;
            }
            i++;
        }
        return ans;
    }
};