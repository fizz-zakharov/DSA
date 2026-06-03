class Solution {
private:
    bool ch(string& small,string& big,int k){
        int i=0;
        int count=0;
        for(char c:big){
            if(c==small[i])i++;
            if(i==small.size()){
                count++;
                i=0;
            }
        }
        return count>=k;
    }

public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int n=s.size();
        map<char,int> m;
        for(int i=0;i<n;i++)m[s[i]]++;
        string st;
        for(auto it:m){
            if(it.second>=k)st.push_back(it.first);
        }
        string ans="";
        queue<string> q;
        q.push("");
        while(!q.empty()){
            string cur=q.front();q.pop();
            for(char c:st){
                string next=cur+c;
                if(ch(next,s,k)){
                    ans=next;
                    q.push(next);
                }
            }
        }
        return ans;
    }
};