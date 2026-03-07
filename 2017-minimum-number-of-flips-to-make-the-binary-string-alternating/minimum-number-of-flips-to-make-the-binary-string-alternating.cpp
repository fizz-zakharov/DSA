class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        string s1=s+s;
        int even=0,odd=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(i&1){
                if(s[i]=='0')odd++;
                else even++;
            }
            else{
                if(s[i]=='1')odd++;
                else even++;
            }
        }
        ans=min(odd,even);
        for(int i=1;i<=n;i++){
            if((i-1)&1){
                if(s[i-1]=='0')odd--;
                else even--;
            }
            else{
                if(s[i-1]=='1')odd--;
                else even--;
            }
            if((n-1+i) &1){
                if(s1[n-1+i]=='0')odd++;
                else even++;
            }
            else{
                if(s1[n-1+i]=='1')odd++;
                else even++;
            }
            ans=min({odd,even,ans});
        }
        return ans;
    }
};