class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> lr;
        vector<int> v(n+1,0);
        for(int i=0;i<=n;i++){
            lr.push_back({max(0,i-ranges[i]),min(n,i+ranges[i])});
        }
        sort(lr.begin(),lr.end());
        for(int i=0;i<=n;i++){
            v[lr[i].first]=max(v[lr[i].first],lr[i].second);
        }

        int r=0,cur=0;
        int ans=0;
        for(int i=0;i<=n;i++){
            if(i>r)return -1;
            if(i>cur){
                cur=r;
                ans++;
            }
            r=max(r,v[i]);
        }
        return ans;
    }
};