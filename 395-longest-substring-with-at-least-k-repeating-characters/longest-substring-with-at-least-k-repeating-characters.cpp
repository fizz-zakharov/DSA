class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        if(k==1)return n;
        vector<vector<int>> pre(n,vector<int>(26,0));
        unordered_map<int,int> m;
        int ans=0;
        for(int i=0;i<n;i++){
            pre[i][s[i]-'a']++;
            m[s[i]-'a']=i;
            if(i>0){
                bool ch=false;
                for(int j=0;j<26;j++){
                    pre[i][j]+=pre[i-1][j];
                    if(pre[i][j]>=k){
                        ch=true;
                    }
                }
                if(ch){
                    int l=-1;
                    bool ch=true;
                    while(ch){
                        ch=false;
                        for(int j=0;j<26;j++){
                            int cnt=pre[i][j]-(l==-1?0:pre[l][j]);
                            if(cnt>0 && cnt<k){
                                l=m[j];      
                                ch=true;
                            }
                        }
                    }
                    ans=max(ans,i-l);       
                }
            }
        }
        return ans;
    }
};