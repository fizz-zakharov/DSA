class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> m1; //+1 if won -1 if lose
        map<int,int> m2; // count number of matches each player played
        for(auto it:matches){
            int w=it[0];
            int l=it[1];
            m1[w]++;
            m2[w]++;
            m2[l]++;
        }
        vector<vector<int>> ans;
        vector<int> v1;
        vector<int> v2;
        for(auto it:m2){
            int player=it.first;
            int mn=it.second;
            if(m1[player]==mn)v1.push_back(player);
            if(m1[player]+1==mn)v2.push_back(player);
        }
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;


    }
};