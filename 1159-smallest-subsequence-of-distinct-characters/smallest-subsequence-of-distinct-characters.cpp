class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        stack<int> st;
        vector<int> seen(26,0);
        unordered_map<char,int> m;
        for(int i=0;i<n;i++){
            m[s[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(seen[s[i]-'a'])continue;
            while(!st.empty() && s[i]<s[st.top()] && m[s[st.top()]]>i){
                seen[s[st.top()]-'a']=0;
                st.pop();
            }
            st.push(i);
            seen[s[i]-'a']=1;
        }
        string ans;
        while(!st.empty()){
            ans.push_back(s[st.top()]);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};