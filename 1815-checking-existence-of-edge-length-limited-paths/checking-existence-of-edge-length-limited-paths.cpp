class DisjointSet{
    vector<int> parent,size,rank;

    public:

        DisjointSet(int n){

            parent.resize(n);
            rank.resize(n,0);
            size.resize(n,0);

            for(int i=0;i<n;i++)parent[i]=i;
        }

        int findultpar(int node){

            if(parent[node]==node)return node;

            return parent[node]=findultpar(parent[node]);
        }

        void unionbyrank(int u,int v){

            int ult_pu=findultpar(u);
            int ult_pv=findultpar(v);

            if(ult_pu==ult_pv)return;

            if(rank[ult_pu]==rank[ult_pv]){

                parent[ult_pu]=ult_pv;
                rank[ult_pv]++;
            }

            else if(rank[ult_pv]>rank[ult_pu]){

                parent[ult_pu]=ult_pv;
            }

            else{

                parent[ult_pv]=ult_pu;
            }
        }
};

class Solution {
public:

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {

        vector<vector<int>> temp;

        for(int i=0;i<queries.size();i++){

            temp.push_back({queries[i][0],queries[i][1],queries[i][2],i});
        }

        sort(edgeList.begin(),edgeList.end(),[](const vector<int>&a,const vector<int>&b){

            return a[2]<b[2];
        });

        sort(temp.begin(),temp.end(),[](const vector<int>&a,const vector<int>&b){

            return a[2]<b[2];
        });

        int i=0;

        int e=edgeList.size();

        vector<bool> ans(queries.size());

        DisjointSet dsu(n);

        for(int j=0;j<temp.size();j++){

            while(i<e && edgeList[i][2] < temp[j][2]){

                dsu.unionbyrank(edgeList[i][0],edgeList[i][1]);

                i++;
            }

            int u=temp[j][0];
            int v=temp[j][1];
            int idx=temp[j][3];

            if(dsu.findultpar(u)==dsu.findultpar(v)){

                ans[idx]=true;
            }

            else{

                ans[idx]=false;
            }
        }

        return ans;
    }
};