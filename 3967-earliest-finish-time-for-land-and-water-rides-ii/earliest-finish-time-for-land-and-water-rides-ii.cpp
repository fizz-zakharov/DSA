class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int minendtime=INT_MAX;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            minendtime=min(minendtime,landStartTime[i]+landDuration[i]);
        }
        for(int i=0;i<m;i++){
            if(waterStartTime[i]<=minendtime){
                ans=min(ans,minendtime+waterDuration[i]);
            }
            else{
                ans=min(ans,waterStartTime[i]+waterDuration[i]);
            }
        }
        minendtime=INT_MAX;
        for(int i=0;i<m;i++){
            minendtime=min(minendtime,waterStartTime[i]+waterDuration[i]);
        }
        for(int i=0;i<n;i++){
            if(landStartTime[i]<=minendtime){
                ans=min(ans,minendtime+landDuration[i]);
            }
            else{
                ans=min(ans,landStartTime[i]+landDuration[i]);
            }
        }
        return ans;
    }
};