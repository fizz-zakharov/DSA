class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        int m=*max_element(nums.begin(),nums.end());
        vector<int> prime(m+1,1);
        for(int i=2;i<=m;i++){
            if(prime[i]==0)continue;
            for(int j=2;j*i<=m;j++){
                prime[j*i]=0;
            }
        }
        prime[1]=0;

        vector<vector<int>> pos(m+1);
        for(int i=0;i<n;i++)pos[nums[i]].push_back(i);

        vector<int> dist(n+1,-1);
        vector<int> vis(m+1,0);

        queue<int> q;
        q.push(0);
        dist[0]=0;
        while(!q.empty()){
            int ind=q.front();
            q.pop();
            if(ind==n-1)return dist[n-1];

            if(ind-1>=0 && dist[ind-1]==-1){
                dist[ind-1]=dist[ind]+1;
                q.push(ind-1);
            }
            if(ind+1<n && dist[ind+1]==-1){
                dist[ind+1]=dist[ind]+1;
                q.push(ind+1);
            }

            if(prime[nums[ind]] && vis[nums[ind]]==0){
                vis[nums[ind]]=1;
                for(int j=1;j*nums[ind]<=m;j++){
                    for(auto it:pos[j*nums[ind]]){
                        if(dist[it]==-1){
                            dist[it]=1+dist[ind];
                            q.push(it);
                        }
                    }
                    pos[j*nums[ind]].clear();

                }
            }
        }
        return dist[n-1];
    }
};