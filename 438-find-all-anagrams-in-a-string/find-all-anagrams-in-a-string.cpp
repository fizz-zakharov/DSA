class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();
        map<int,int> mp;
        for(int i=0;i<m;i++)mp[p[i]]++;
        map<int,int> m2;
        vector<int> ans;
        for(int i=0;i<m;i++){
            m2[s[i]]++;
        }
        if(m2==mp)ans.push_back(0);
        int i=m,j=0;
        while(i<n){
            m2[s[j]]--;
            if(m2[s[j]]==0){
                m2.erase(s[j]);
            }
            m2[s[i]]++;
            i++;
            j++;
            if(m2==mp)ans.push_back(j);
        }
        return ans;
    }
};