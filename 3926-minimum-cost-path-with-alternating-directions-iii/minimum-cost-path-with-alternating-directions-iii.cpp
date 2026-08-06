class Solution {
public:
    const vector<int> dx={0,1,-1,0};
    const vector<int> dy={1,0,0,-1};
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        //pq -> <cost,i,j,parity>
        priority_queue<pair<long long,pair<long long,pair<long long,long long>>>,vector<pair<long long,pair<long long,pair<long long,long long>>>>,greater<pair<long long,pair<long long,pair<long long,long long>>>>> pq;
        pq.push({1,{1,{0,0}}});
        vector<vector<vector<long long>>> dp(m,vector<vector<long long>>(n,vector<long long>(2,LLONG_MAX)));
        //parity=0 -> even, 1->odd
        dp[0][0][1]=1;
        while(!pq.empty()){
            long long cost=pq.top().first;
            long long parity=pq.top().second.first;
            long long i=pq.top().second.second.first;
            long long j=pq.top().second.second.second;
            pq.pop();
            if(i==m-1 && j==n-1)return cost;
            int newparity=(parity==1)?0:1;
            if(dp[i][j][parity]!=cost)continue;

            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(!(x>=0 && x<m && y>=0 && y<n))continue;
                if(dp[i][j][parity]+penalty[i][j]<dp[i][j][newparity]){
                    dp[i][j][newparity]=dp[i][j][parity]+penalty[i][j];
                    pq.push({dp[i][j][newparity],{newparity,{i,j}}});
                }
                if(parity&1){
                    if(k<2){
                        if((x+1)*(y+1)+dp[i][j][parity]<dp[x][y][newparity]){
                            dp[x][y][newparity]=(x+1)*(y+1)+dp[i][j][parity];
                            pq.push({dp[x][y][newparity],{newparity,{x,y}}});
                        }
                    }
                    else{
                        if((x+1)*(y+1)+penalty[i][j]+dp[i][j][parity]<dp[x][y][newparity]){
                            dp[x][y][newparity]=(x+1)*(y+1)+penalty[i][j]+dp[i][j][parity];
                            pq.push({dp[x][y][newparity],{newparity,{x,y}}});
                        }
                    }
                }
                else{
                    if(k>=2){
                        if((x+1)*(y+1)+dp[i][j][parity]<dp[x][y][newparity]){
                            dp[x][y][newparity]=(x+1)*(y+1)+dp[i][j][parity];
                            pq.push({dp[x][y][newparity],{newparity,{x,y}}});
                        }
                    }
                    else{
                        if((x+1)*(y+1)+penalty[i][j]+dp[i][j][parity]<dp[x][y][newparity]){
                            dp[x][y][newparity]=(x+1)*(y+1)+penalty[i][j]+dp[i][j][parity];
                            pq.push({dp[x][y][newparity],{newparity,{x,y}}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};