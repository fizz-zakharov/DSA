class Solution {
private:
    int dp[50002];
    int fn(int i,vector<pair<pair<int,int>,int>>&v){
        if(i>=v.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int a=fn(i+1,v);
        int b=0;
        pair<pair<int,int>,int> target={{v[i].first.second,0},0};
        auto it=lower_bound(v.begin(),v.end(),target);
        if(it==v.end())b=v[i].second;
        else{
            int ind=it-v.begin();
            b=v[i].second+fn(ind,v);
        }
        return dp[i] = max(a,b);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<pair<pair<int,int>,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({{startTime[i],endTime[i]},profit[i]});
        }
        sort(v.begin(),v.end());
        memset(dp,-1,sizeof(dp));
        return fn(0,v);
    }
};