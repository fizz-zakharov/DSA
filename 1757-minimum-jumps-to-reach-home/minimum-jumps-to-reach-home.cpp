class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        map<int,int> m;
        for(auto it:forbidden)m[it]++;

        vector<vector<int>> visited(6001,vector<int>(2,0));

        queue<pair<int,pair<int,int>>> q;//{jumps,{position,state{1->forward,0->backward}}}
        q.push({0,{0,1}});
        visited[0][1]=1;

        while(!q.empty()){
            int jumps=q.front().first;
            int position=q.front().second.first;
            int state=q.front().second.second;
            q.pop();

            if(position==x)return jumps;

            if(position+a<=6000 && m[position+a]!=1 && visited[position+a][1]!=1){
                visited[position+a][1]=1;
                q.push({jumps+1,{position+a,1}});
            }

            if(position-b>=0 && m[position-b]!=1 && visited[position-b][0]!=1 && state==1){
                visited[position-b][0]=1;
                q.push({jumps+1,{position-b,0}});
            }
        }
        return -1;
    }
};
