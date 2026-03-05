class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int c=0,q=0;
        for(int i=0;i<n;i++){
            if(i&1){
                if(s[i]=='0')c++;
                else q++;
            }
            else{
                if(s[i]=='1')c++;
                else q++;
            }
        }
        return min(c,q);
    }
};