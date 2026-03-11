class Solution {
public:
    int bitwiseComplement(int n) {
        int temp=n;
        if(n==0)return 1;
        string k;
        while(temp){
            if(temp&1)k.push_back('1');
            else k.push_back('0');
            temp/=2;
        }
        reverse(k.begin(),k.end());
        for(int i=0;i<k.size();i++){
            if(k[i]=='1')k[i]='0';
            else k[i]='1';
        }
        int ans=0;
        for(int i=0;i<k.size();i++){
            ans=(ans<<1);
            if(k[i]=='1')ans++;
        }
        return ans;
    }
};