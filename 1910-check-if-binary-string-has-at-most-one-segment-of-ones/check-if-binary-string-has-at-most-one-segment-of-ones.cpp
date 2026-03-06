class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        int endind=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                endind=i;
                break;
            }
        }
        for(int i=0;i<=endind;i++){
            if(s[i]=='0')return false;
        }
        return true;
    }
};