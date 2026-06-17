class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.size();
        long long len=0;
        for(int i=0;i<n;i++){
            if(s[i]=='#')len=2*len;
            else if(s[i]=='*'){
                if(len>0)len--;
            }
            else if(s[i]=='%')continue;
            else{
                len++;
            }
        }
        if(k>=len)return '.';
        for(int i=n-1;i>=0;i--){
            if(s[i]=='#'){
                len=len/2;
                if(k-len>=0)k=k-len;
            }
            else if(s[i]=='*'){
                len++;
            }
            else if(s[i]=='%'){
                k=len-k-1;
            }
            else{
                len--;
            }
            if(len==k){
                return s[i];
            }
        }
        return '.';
    }
};