class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int landstart=landStartTime[i];
            int landdur=landDuration[i];
            for(int j=0;j<m;j++){
                int waterstart=waterStartTime[j];
                int waterdur=waterDuration[j];
                if(landstart+landdur<=waterstart){
                    ans=min(ans,waterstart+waterdur);
                }
                if(landstart+landdur>waterstart){
                    ans=min(ans,landstart+landdur+waterdur);
                }
                if(waterstart+waterdur<=landstart){
                    ans=min(ans,landstart+landdur);
                }
                if(waterstart+waterdur>landstart){
                    ans=min(ans,waterstart+waterdur+landdur);
                }

            }
        }
        return ans;
    }
};