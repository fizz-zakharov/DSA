class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        vector<int> begins;
        for(int i=0;i<n;i++){
            begins.push_back(events[i][0]);
        }
        vector<int> suff(n); //suffix max array
        int k=INT_MIN;
        for(int i=n-1;i>=0;i--){
            k=max(k,events[i][2]);
            suff[i]=k;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int end=events[i][1];
            int value=events[i][2];
            auto it=lower_bound(begins.begin(),begins.end(),end+1);
            if(it==begins.end()){
                ans=max(ans,value);
                continue;
            }
            int index=it-begins.begin();
            ans=max(ans,value+suff[index]);
        }
        return ans;
    }
};