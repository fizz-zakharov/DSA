class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(auto it:words){
            m[it]++;
        }
        auto comp=[](const pair<int,string> p,const pair<int,string> q){
            if(p.first!=q.first)return p.first<q.first;
            return p.second>q.second; 
        };
        priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(comp)> pq(comp);
        for(auto it:m){
            pq.push({it.second,it.first});
        }
        vector<string> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};