class Solution {
public:
    int longestAwesome(string s) {
        int n=s.size();
        vector<int> freq(1024,-2);
        int mask=0;
        freq[0]=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            mask=(mask)^(1<<(s[i]-'0'));
            if(freq[mask]!=-2){
                ans=max(ans,i-freq[mask]);
            }
            for(int j=0;j<10;j++){
                int newmask=(mask)^(1<<j);
                if(freq[newmask]!=-2){
                    ans=max(ans,i-freq[newmask]);
                }
            }
            if(freq[mask]==-2)freq[mask]=i;
        }
        return ans;
    }
};