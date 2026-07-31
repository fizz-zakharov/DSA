class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        cout<<n<<'\n';
        unordered_map<char,int> freq;
        for(int i=0;i<n;i++)freq[word[i]]++;
        priority_queue<pair<int,char>> pq;
        for(auto it:freq){
            pq.push({it.second,it.first});
        }
        unordered_map<char,int> m;
        int ans=0;
        int c=0;
        int t=1;
        while(!pq.empty()){
            c++;
            if(c==9){
                c=1;
                t++;
            }
            m[pq.top().second]=t;
            pq.pop();
        }
        for(int i=0;i<n;i++)ans+=m[word[i]];
        return ans;
    }
};