class Solution {
private:    
    int fn(int i,int j,string& s){
        if(i>=j){
            if(i==j)return 1;
            return 0;
        }
        int ans=0;
        for(int k=i;k<=j;k++){
            bool ch=true;
            for(int x=i;x<=(i+k)/2;x++){
                if(s[x]!=s[i+k-x]){
                    ch=false;
                    break;
                }
            }
            if(ch){
                ans++;
            }
        }
        return ans+fn(i+1,j,s);
    }
public:
    int countSubstrings(string s) {
        int n=s.size();
        return fn(0,n-1,s);
    }
};