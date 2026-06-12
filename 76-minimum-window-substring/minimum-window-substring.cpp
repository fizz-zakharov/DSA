class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        unordered_map<char,int> f1;
        unordered_map<char,int> f2;
        for(auto it:t)f2[it]++;
        string ans;
        int count=0;
        int sz=INT_MAX;
        int i=0,j=0;
        int l=-1,r=-1;
        bool ch=false;
        while(j<n){
            f1[s[j]]++;
            if(f2.find(s[j])!=f2.end() && f1[s[j]]<=f2[s[j]])count++;
            if(count==m){
                while(i<=j && count==m){
                    if(j-i+1<sz){
                        l=i;
                        r=j;
                        sz=j-i+1;
                        ch=true;
                    }
                    f1[s[i]]--;
                    if(f2.find(s[i])!=f2.end() && f1[s[i]]<f2[s[i]]){
                        count--;
                    }
                    i++;
                }
            }
            j++;
        }
        if(!ch)return ans;
        ans=s.substr(l,r-l+1);
        return ans;
    }
};