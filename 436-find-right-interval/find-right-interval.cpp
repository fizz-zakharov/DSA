class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        map<vector<int>,int> m;
        for(int i=0;i<n;i++){
            m[intervals[i]]=i;
        }
        vector<int> ans(n);
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++){
            vector<int> target={intervals[i][1],INT_MIN};
            auto it=lower_bound(intervals.begin(),intervals.end(),target);
            if(it==intervals.end()){
                ans[m[intervals[i]]]=-1;
            }
            else{
                int ind=it-intervals.begin();
                ans[m[intervals[i]]]=m[intervals[ind]];
            }
        }
        return ans;
    }
};