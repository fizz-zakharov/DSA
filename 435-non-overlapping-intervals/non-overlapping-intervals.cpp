class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int ans=0;
        int l=intervals[0][0],r=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<r){
                if(r>intervals[i][1]){
                    l=intervals[i][0];
                    r=intervals[i][1];
                }
                ans++;
                continue;
            }
            l=intervals[i][0];
            r=intervals[i][1];
        }
        return ans;
    }
};