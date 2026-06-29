class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n=patterns.size();
        int m=word.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int j=0;
            int c=0;
            for(int k=0;k<m;k++){
                int t=k;
                while(j<patterns[i].size() && t<m && patterns[i][j]==word[t]){
                    j++;
                    t++;
                    c++;
                }
                if(c==patterns[i].size()){
                    ans++;
                    break;
                }
                j=0;
                c=0;
            }
        }
        return ans;
    }
};