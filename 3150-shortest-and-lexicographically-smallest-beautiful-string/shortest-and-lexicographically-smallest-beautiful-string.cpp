class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        vector<string> v;
        int j=0;
        unordered_map<char,int> m;
        int len=INT_MAX;
        for(int i=0;i<n;i++){
            m[s[i]]++;
            while(m['1']==k){
                v.push_back(s.substr(j,i-j+1));
                len=min(len,i-j+1);
                m[s[j]]--;
                j++;
            }
        }
        priority_queue<string,vector<string>,greater<string>> pq;
        for(int i=0;i<v.size();i++){
            if(v[i].size()==len){
                pq.push(v[i]);
            }
        }
        if(pq.empty())return "";
        return pq.top();
    }
};