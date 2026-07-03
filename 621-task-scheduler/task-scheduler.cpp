class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m=tasks.size();
        vector<int> freq(26,0);
        for(int i=0;i<m;i++)freq[tasks[i]-'A']++;
        priority_queue<int> pq;
        for(int i=0;i<26;i++)if(freq[i]>0)pq.push(freq[i]);
        int ans=0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int curf=pq.top();
                    pq.pop();
                    curf--;
                    temp.push_back(curf);
                }
            }
            for(int i=0;i<temp.size();i++){
                if(temp[i]>0)pq.push(temp[i]);
            }
            if(pq.empty())ans+=temp.size();
            else ans+=n+1;
            
        }
        return ans;

    }
};