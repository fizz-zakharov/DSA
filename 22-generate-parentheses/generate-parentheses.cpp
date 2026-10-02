class Solution {
private:
    int k;
    vector<string> ans;
    set<string> st;

    void fn(int i,int c,string& s){
        if(i>=k){
            if(c==0)st.insert(s);
            return;
        }
        if(c>0){
            s.push_back(')');
            fn(i+1,c-1,s);
            s.pop_back();
        }
        s.push_back('(');
        fn(i+1,c+1,s);
        s.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        k=2*n;
        string temp;
        fn(0,0,temp);
        for(auto it:st)ans.push_back(it);
        return ans;
    }
};