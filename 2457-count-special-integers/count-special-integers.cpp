class Solution {
private:
    int fn(int i,int tight,int mask,string& s){
        if(i>=s.size()){
            return 1;
        }
        int ans=0;
        if(tight==1){
            for(int j=0;j<=s[i]-'0';j++){
                if(mask&(1<<j))continue;
                int newmask=mask;
                if(j==0 && mask==0){
                    newmask=mask;
                }
                else{
                    newmask=mask|(1<<j);
                }
                int newtight=0;
                if(j==s[i]-'0')newtight=1;
                ans+=fn(i+1,newtight,newmask,s);
            }
        }
        else{
            for(int j=0;j<=9;j++){
                if(mask&(1<<j))continue;
                int newmask=mask;
                if(j==0 && mask==0){
                    newmask=mask;
                }
                else{
                    newmask=mask|(1<<j);
                }
                ans+=fn(i+1,0,newmask,s);
            }
        }
        return ans;
    }
public:
    int countSpecialNumbers(int n) {
        string s=to_string(n);
        return fn(0,1,0,s)-1;
    }
};