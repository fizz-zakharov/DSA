class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        vector<vector<bool>> preq(n,vector<bool>(n,false));
        for(auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            preq[u][v]=true;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(preq[i][k] && preq[k][j])preq[i][j]=true;
                }
            }
        }
        vector<bool> ans;
        for(auto it:queries){
            int u=it[0];
            int v=it[1];
            if(preq[u][v])ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};