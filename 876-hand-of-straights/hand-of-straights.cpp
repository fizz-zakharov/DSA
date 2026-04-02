class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)return false;
        map<int,int> m;
        for(int i=0;i<n;i++)m[hand[i]]++;
        priority_queue<pair<int,int>> pq;
        for(auto it:m){
            pq.push({it.first,it.second});
        }
        int k=n/groupSize; //k groups and we want each group to have groupSize consecutive cards
        while(k--){
            int temp=groupSize;
            vector<pair<int,int>> rem;
            int prev=-1;
            while(temp--){
                int num=pq.top().first;
                int freq=pq.top().second;
                if(freq>1)rem.push_back({num,freq-1});
                pq.pop();
                if(prev!=-1 && num+1!=prev)return false;
                prev=num;
            }
            for(int i=0;i<rem.size();i++)pq.push(rem[i]);
        }
        return true;

        
    }
};