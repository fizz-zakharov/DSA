class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        if(s[n-1]=='1')return false;
        vector<int> v(n+1,0);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=v[i];
            if(s[i]=='0' && (i==0 || sum>0)){
                if(i+minJump>n-1)continue;
                int l=min(i+minJump,n-1);
                v[l]+=1;
                int r=min(i+maxJump+1,n);
                v[r]-=1;
            }
        }
        return sum>0;
    }
};