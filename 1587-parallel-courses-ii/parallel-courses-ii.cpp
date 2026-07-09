class Solution {
private:
    unordered_map<long long,int> dp;
    int fn(int mask,int semMask,int taken,int k,vector<int>&pre, int n){
        if(mask==(1<<n)-1) return 0;
        long long key = ((long long)mask<<30) | ((long long)semMask<<15) | taken;
        if(dp.count(key)) return dp[key];
        int a=1e9;
        for(int i=0;i<n;i++){
            if(!((mask|semMask)&(1<<i)) && (pre[i]&mask)==pre[i]){
                int newSemMask = semMask|(1<<i);
                if(taken+1==k)
                    a=min(a,1+fn(mask|newSemMask,0,0,k,pre,n));
                else
                    a=min(a,fn(mask,newSemMask,taken+1,k,pre,n));
            }
        }
        if(taken>0 && a==1e9){
            a=min(a,1+fn(mask|semMask,0,0,k,pre,n));
        }
        return dp[key] = a;
    }
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> pre(n,0);
        for(auto it:relations){
            int u=it[0]-1;
            int v=it[1]-1;
            pre[v]=(pre[v]|(1<<u));
        }
        dp.clear();
        return fn(0,0,0,k,pre,n);
    }
};