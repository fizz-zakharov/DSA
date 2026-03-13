class Solution {
private:
    vector<int> fn(int n,string& s,vector<int>& temp,vector<int>&vis){
        if(temp.size()==(1<<n)){
            return temp;
        }
        for(int i=0;i<n;i++){
            string ts=s;
            if(s[i]=='0')ts[i]='1';
            else ts[i]='0';
            int t=n;
            int g=0;
            int j=0;
            while(t--){
                g=(g<<1);
                if(ts[j]=='1')g++;
                j++;
            }
            if(!vis[g]){
                vis[g] = 1;      
                temp.push_back(g);
                auto res = fn(n, ts, temp, vis);  
                if(!res.empty())return res;
                temp.pop_back();     
                vis[g] = 0;          
            }
        }
        vector<int> empty;
        return empty;
    }
public:
    vector<int> grayCode(int n) {
        string s;
        int t=n;
        while(t--)s.push_back('0');
        vector<int> vis((1<<n),0);
        vis[0]=1;
        vector<int> x;
        x.push_back(0);
        return fn(n,s,x,vis);
    }
};