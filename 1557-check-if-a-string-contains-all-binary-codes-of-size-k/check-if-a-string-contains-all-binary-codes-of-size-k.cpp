class Solution {
private:
    void fn(int k,string& s,map<string,int>&m,bool& check){
        if(!check)return;
        if(s.size()==k){
            if(m[s]==0)check=false;
            return;
        }
        s.push_back('1');
        fn(k,s,m,check);
        s.pop_back();
        
        s.push_back('0');
        fn(k,s,m,check);
        s.pop_back();

        return;
    }
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        map<string,int> m;
        string temp;
        if(k>s.size())return false;
        for(int i=0;i<k;i++)temp.push_back(s[i]);
        m[temp]++;
        for(int i=k;i<n;i++){
            temp.erase(0,1);
            temp.push_back(s[i]);
            m[temp]++;
        }
        string t;
        bool c=true;
        fn(k,t,m,c);
        return c;

    }
};