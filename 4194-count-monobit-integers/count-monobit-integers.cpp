class Solution {
public:
    int countMonobit(int n) {
        int ans=0;
        for(int i=0;i<=n;i++){
            if(i==0)ans++;
            else{
                if(((i+1)&i)==0)ans++;
            }
        }
        return ans;
    }
};