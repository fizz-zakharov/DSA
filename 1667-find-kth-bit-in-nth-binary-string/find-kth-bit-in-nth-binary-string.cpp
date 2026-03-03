class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        int t=n-1;
        while(t--){
            string x=s;
            string temp=s;
            int sz=s.size();
            for(int i=0;i<sz;i++){
                if(temp[i]=='1')temp[i]='0';
                else temp[i]='1';
            }
            reverse(temp.begin(),temp.end());
            s=x+'1'+temp;
        }
        return s[k-1];
    }
};