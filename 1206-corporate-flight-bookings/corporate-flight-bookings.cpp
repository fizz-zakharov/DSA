class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> v(n+1);
        for(auto it:bookings){
            int l=it[0]-1;
            int r=it[1];
            int val=it[2];
            v[l]+=val;
            v[r]-=val;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=v[i];
            v[i]=sum;
        }
        v.pop_back();
        return v;
    }
};