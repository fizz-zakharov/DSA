class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(m<n)return false;
        map<char,int> m1;
        map<char,int> m2;
        for(int i=0;i<n;i++){
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        if(m1==m2)return true;
        int j=0;
        for(int i=n;i<m;i++){
            m2[s2[j]]--;
            if(m2[s2[j]]==0)m2.erase(s2[j]);
            m2[s2[i]]++;
            if(m1==m2)return true;
            j++;
        }
        return false;
        

    }
};