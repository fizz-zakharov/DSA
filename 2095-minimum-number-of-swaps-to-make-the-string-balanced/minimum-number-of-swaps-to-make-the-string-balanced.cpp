class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        stack<char> st;
        int j=n-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='['){
                st.push(s[i]);
                continue;
            }
            if(s[i]==']'){
                if(!st.empty()){
                    st.pop();
                    continue;
                }
                else{
                    while(s[j]!='['){
                        j--;
                    }
                    swap(s[i],s[j]);
                    st.push('[');
                    ans++;
                }
            }
        }
        return ans;
    }
};