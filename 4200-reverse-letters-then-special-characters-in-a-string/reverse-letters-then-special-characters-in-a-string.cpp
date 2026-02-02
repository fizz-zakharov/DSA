class Solution {
public:
    string reverseByType(string s) {
        int n=s.size();
        stack<char> st1,st2;
        for(int i=0;i<n;i++){
            if(s[i]>='a'&&s[i]<='z')st1.push(s[i]);
            else{
                st2.push(s[i]);
            }
        }
        string ans;
        for(int i=0;i<n;i++){
            if(s[i]>='a'&&s[i]<='z'){
                ans.push_back(st1.top());
                st1.pop();
            }
            else{
                ans.push_back(st2.top());
                st2.pop();
            }
        }
        return ans;
    }
};