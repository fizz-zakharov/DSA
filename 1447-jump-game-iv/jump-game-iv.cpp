class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            m[arr[i]].push_back(i);
        }
        vector<int> vis(n);
        vis[0]=1;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            int ind=q.front().first;
            int steps=q.front().second;
            int val=arr[ind];
            q.pop();
            if(ind==n-1)return steps;
            if(ind-1>=0&&vis[ind-1]==0){
                vis[ind-1]=1;
                q.push({ind-1,steps+1});
            }
            if(ind+1<n&&vis[ind+1]==0){
                vis[ind+1]=1;
                q.push({ind+1,steps+1});
            }
            for(auto it:m[val]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push({it,steps+1});
                }
            }
            m[val].clear();
        }
        return 0;

    }
};