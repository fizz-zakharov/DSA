class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=source.size();

        //adjacency vector
        vector<vector<pair<int,int>>> adj(26);
        int m=original.size();
        for(int i=0;i<m;i++){
            int u=original[i]-'a';
            int v=changed[i]-'a';
            int w=cost[i];
            adj[u].push_back({v,w});
        }
        //shortest distance x->y matrix
        vector<vector<long long>> path(26,vector<long long>(26,INT_MAX));

        //precomputation
        for(int i = 0; i < 26; i++) {
            int src = i;

            priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

            vector<long long> dist(26, INT_MAX);
            dist[src] = 0;
            pq.push({0, src}); // distance, node

            while (!pq.empty()) {
                long long dis = pq.top().first;
                int node = pq.top().second;
                pq.pop();

                if (dis > dist[node]) continue;

                for (auto it : adj[node]) {
                    int adjnode = it.first;
                    long long weight = it.second;

                    if (dist[node] + weight < dist[adjnode]) {
                        dist[adjnode] = dist[node] + weight;
                        pq.push({dist[adjnode], adjnode});
                    }
                }
            }

            for (int j = 0; j < 26; j++) {
                path[i][j] = dist[j];
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            if(source[i]==target[i])continue;
            int u=source[i]-'a';
            int v=target[i]-'a';
            if(path[u][v]==INT_MAX)return -1;
            ans+=path[u][v];
        }
        return ans;
        
    }
};