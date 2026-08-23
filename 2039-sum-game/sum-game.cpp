class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int lsum=0;
        int rsum=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(i<n/2 &&  num[i]!='?'){
                lsum+=num[i]-'0';
            }
            else if(i>=n/2 && num[i]!='?'){
                rsum+=num[i]-'0';
            }
            else{
                if(i<n/2)c++;
                else c--;
            }
        }
        if(c==0){
            return (lsum!=rsum);
        }
        if(c&1)return true;
        return (2*(lsum-rsum)!=-9*c);
    }
};