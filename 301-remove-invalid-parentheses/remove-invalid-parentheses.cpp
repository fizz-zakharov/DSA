class Solution {
private:
    int n,k;
    set<string> st;
    bool valid(string& s){
        int ct=0;
        for(int i=0;i<k;i++){
            if(s[i]=='(')ct++;
            else if(s[i]==')'){
                if(ct==0)return false;
                else ct--;
            }
        }
        return (ct==0);
    }

    void fn(int i,int j,string& temp,string& s){
        if(j==0){
            if(valid(temp)){
                st.insert(temp);
            }
            return;
        }
        if(i>=n)return;

        if(s[i]>='a' && s[i]<='z'){
            temp.push_back(s[i]);
            fn(i+1,j-1,temp,s);
            temp.pop_back();
        }
        else{
            fn(i+1,j,temp,s);
            temp.push_back(s[i]);
            fn(i+1,j-1,temp,s);
            temp.pop_back();
        }
        return;
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        n=s.size();
        k=n;
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')c++;
            else if(s[i]==')'){
                if(c==0){
                    k--;
                }
                else c--;
            }
        }
        k-=c;
        string temp;
        fn(0,k,temp,s);
        vector<string> ans;
        for(auto it:st)ans.push_back(it);
        return ans;
    }
};