class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n=rooms.size();
        int q=queries.size();
        
        vector<vector<int>> v;
        
        for(int i=0;i<q;i++){
            v.push_back({queries[i][1],queries[i][0],i});
        }

        sort(rooms.begin(),rooms.end(),[](const vector<int>&a,const vector<int>&b){
            if(a[1]==b[1]){
                return a[0]<b[0];
            }
            else return a[1]>b[1];
        });

        sort(v.begin(),v.end(),[](const vector<int>&a,const vector<int>&b){
            return a[0]>b[0];
        });

        set<int> temp;

        int i=0,j=0;

        vector<int> ans(q,-1);

        while(j<q){

            while(i<n && rooms[i][1]>=v[j][0]){
                temp.insert(rooms[i][0]);
                i++;
            }

            if(temp.empty()){
                j++;
                continue;
            }

            auto it = temp.lower_bound(v[j][1]);

            int val=-1;

            if(it!=temp.end()){
                val=*it;
            }

            if(it!=temp.begin()){
                auto p=prev(it);

                if(val==-1 || abs(*p-v[j][1])<=abs(val-v[j][1])){
                    val=*p;
                }
            }

            ans[v[j][2]]=val;

            j++;
        }

        return ans;
    }
};