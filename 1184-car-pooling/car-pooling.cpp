class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        vector<int> diff(1002);
        for(int i=0;i<n;i++){
            int l=trips[i][1];
            int r=trips[i][2];
            int val=trips[i][0];
            diff[l]+=val;
            diff[r]-=val;
        }
        int sum=0;
        for(int i=0;i<diff.size();i++){
            sum+=diff[i];
            if(sum>capacity)return false;
        }
        return true;
    }
};