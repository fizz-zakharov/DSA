class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            v.push_back({times[i][0],times[i][1],i}); //{start,end,friendnumber}
        }
        sort(v.begin(),v.end());
        priority_queue<int,vector<int>,greater<int>> freeSeats;
        for(int j=0;j<n;j++) freeSeats.push(j);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        //{endtime,seatavailable}
        pq.push({v[0][1],0});
        freeSeats.pop();
        int i=1;
        while(i<n){
            while(!pq.empty()&&pq.top().first<=v[i][0]){
                freeSeats.push(pq.top().second);
                pq.pop();
            }
            int newseat=freeSeats.top();
            freeSeats.pop();
            if(v[i][2]==targetFriend){
                return newseat;
            }
            pq.push({v[i][1],newseat});
            i++;
        }
        return 0;

    }
};