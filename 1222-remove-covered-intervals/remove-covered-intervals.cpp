class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int l=intervals[0][0];
        int r=intervals[0][1];
        int ans=1;
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=l && intervals[i][1]<=r)continue;
            else if(intervals[i][0]==l && intervals[i][1]>r){
                r=intervals[i][1];
            }
            else{
                l=intervals[i][0];
                r=intervals[i][1];
                ans++;
            }
        }
        return ans;
    }
};