class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        if(n==0)return {newInterval};
        int l=newInterval[0];
        int r=newInterval[1];
        bool ch=true;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(l>=intervals[i][0]&&l<=intervals[i][1]){
                l=intervals[i][0];
                r=max(r,intervals[i][1]);
            }
            else if(r>=intervals[i][0]&&r<=intervals[i][1]){
                l=min(l,intervals[i][0]);
                r=intervals[i][1];
            }
            else if(intervals[i][0]>=l && intervals[i][1]<=r)continue;
            else{
                if(r<intervals[i][0] && ch){
                    ans.push_back({l,r});
                    ch=false;
                }
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
        }
        if(ch)ans.push_back({l,r});
        return ans;
    }
};