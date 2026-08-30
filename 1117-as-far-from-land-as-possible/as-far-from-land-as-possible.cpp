class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<pair<int,int>> land,water;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)land.push_back({i,j});
                else water.push_back({i,j});
            }
        }

        if(land.size()==0 || water.size()==0)return -1;
        int ans=INT_MIN;
        for(int i=0;i<water.size();i++){
            int nearest_land_cell=INT_MAX;
            for(int j=0;j<land.size();j++){
                nearest_land_cell=min(nearest_land_cell,abs(water[i].first-land[j].first)+abs(water[i].second-land[j].second));
            }
            ans=max(ans,nearest_land_cell);
        }
        return ans;
    }
};