class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n=s.size();
        bool ch=false;
        string ans=s;
        int p=-1;
        for(int i=n-1;i>=0;i--){
            int pos=s[i]-'a'+1;
            if(pos+1>k)continue;
            for(int j=pos+1;j<=k;j++){
                char c='a'+j-1;
                if(i>1){
                    if(c!=s[i-1] && c!=s[i-2]){
                        ch=true;
                        ans[i]=c;
                        p=i;
                        break;
                    }
                }
                else if(i>0){
                    if(c!=s[i-1]){
                        ch=true;
                        ans[i]=c;
                        p=i;
                        break;
                    }
                }
                else{
                    ans[i]=c;
                    ch=true;
                    p=i;
                    break;
                }
            }
            if(ch)break;
        }
        if(!ch)return "";
        for(int i=p+1;i<n;i++){
            bool done=false;
            for(int c=1;c<=k;c++){
                char t='a'+c-1;
                if(i>1){
                    if(t!=ans[i-1] && t!=ans[i-2]){
                        ans[i]=t;
                        done=true;
                        break;
                    }
                }
                else if(i>0){
                    if(t!=ans[i-1]){
                        ans[i]=t;
                        done=true;
                        break;
                    }
                }
                if(done)break;
            }
        }
        return ans;
    }
};