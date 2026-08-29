class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        map<pair<int,int>,shared_ptr<priority_queue<int,vector<int>,greater<int>>>> m;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        vector<int> ans;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            auto pq = make_shared<priority_queue<int,vector<int>,greater<int>>>();
            m[v[i]]=pq;
            m[v[i]]->push(v[i].first);
            int j=i+1;
            while(j<n && abs(v[j].first-v[j-1].first)<=limit){
                m[v[j]]=pq;
                m[v[j]]->push(v[j].first);
                j++;
            }
            j--;
            i=j;
        }
        for(int i=0;i<n;i++){
            ans.push_back(m[{nums[i],i}]->top());
            m[{nums[i],i}]->pop();
        }
        return ans;
    }
};