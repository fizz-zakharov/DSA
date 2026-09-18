class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        map<int,int> m1,m2;
        vector<int> pre(n+1,0),suff(n+1,0);
        vector<int> l(n+1,1e9),r(n+1,1e9);
        m1[0]=0;
        m2[0]=n;
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+arr[i];
            m1[pre[i+1]]=i+1;
            if(m1.find(pre[i+1]-target)!=m1.end()){
                l[i+1]=min(l[i],i+1-m1[pre[i+1]-target]);
            }
            else l[i+1]=l[i];
        }
        for(int i=n;i>0;i--){
            suff[i-1]=suff[i]+arr[i-1];
            m2[suff[i-1]]=i-1;
            if(m2.find(suff[i-1]-target)!=m2.end()){
                r[i-1]=min(r[i],m2[suff[i-1]-target]-(i-1)); 
            }
            else r[i-1]=r[i];
        }
        int ans=1e9;
        for(int i=0;i<=n;i++){
            ans=min(ans,l[i]+r[i]);
        }
        return ans >= 1e9 ? -1 : ans; 
    }
};