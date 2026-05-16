class Solution {
vector<string> ans;
private:
    bool fn(int i, string s, string temp, map<string, int>& m, int n){
        // base case
        if (i >= n) {
            ans.push_back(temp);
            return true;
        }
        bool found = false;
        for (int l = 1;l<=n-i;l++){
            string x = s.substr(i,l);
            if (m[x]>0){
                bool ch = false;
                if (temp.size() > 0){
                    temp.push_back(' ');
                    ch = true;
                }
                temp+=x;
                found|=fn(i+l,s,temp,m,n);

                // backtrack
                if(ch)temp.erase(temp.size() - x.size() - 1, x.size() + 1);
                else temp.erase(temp.size() - x.size(), x.size());
            }
        }

        return found;
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        map<string,int> m;
        for (auto it:wordDict)m[it]++;
        string z;
        fn(0,s,z,m,n);
        return ans;
    }
};