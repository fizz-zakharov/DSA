class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n=tasks.size();
        vector<pair<int,int>> dp(1<<n,{n+1,0});
        dp[0]={1,0};

        for(int mask=1;mask<(1<<n);mask++){
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    auto prev=dp[mask^(1<<i)];
                    if(prev.second+tasks[i]<=sessionTime){
                        prev.second+=tasks[i];
                    }
                    else{
                        prev.first++;
                        prev.second=tasks[i];
                    }
                    dp[mask]=min(dp[mask],prev);
                }
            }
        }
        return dp[(1<<n)-1].first;
    }
};