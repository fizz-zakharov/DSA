class Solution {
private:
    void generateset(int i,int n,vector<int>& temp,vector<vector<int>>& sets){
        if(i>=n){
            sets.push_back(temp);
            return;
        }
        temp.push_back(i);
        generateset(i+1,n,temp,sets);
        temp.pop_back(); 
        generateset(i+1,n,temp,sets);
    }

    bool floydwarshal(vector<int>& v,int maxdist,vector<vector<int>>& roads,int n){
        if(v.size()<2)return true;
        set<int> s(v.begin(), v.end());
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

        for(auto it:v)dist[it][it]=0;
        for(auto it:roads){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(s.count(u) && s.count(v)){
                dist[u][v]=min(dist[u][v],w);
                dist[v][u]=min(dist[v][u],w);
            }
        }

        for(auto k:v){
            for(auto i:v){
                for(auto j:v){
                    if (dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        for(int i = 0;i<v.size();i++){
            for(int j = i+1;j<v.size();j++){
                if(dist[v[i]][v[j]]>maxdist)return false;
            }
        }
        return true;
    }

public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<int> temp;
        vector<vector<int>> sets;
        generateset(0,n,temp,sets);
        int ans=0;
        for(auto it:sets){
            if(floydwarshal(it,maxDistance,roads,n)){
                ans++;
            }
        }
        return ans;
    }
};