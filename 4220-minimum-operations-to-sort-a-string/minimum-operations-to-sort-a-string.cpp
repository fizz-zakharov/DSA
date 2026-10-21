class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if(n==2 && s[0]>s[1])return -1;
        char mn='z',mx='a';
        for(int i=0;i<n;i++){
            if(s[i]<mn)mn=s[i];
            if(s[i]>mx)mx=s[i];
        }
        string temp=s;
        sort(temp.begin(),temp.end());
        if(temp==s)return 0;
        if(s[0]==mn || s[n-1]==mx)return 1;
        if(s[0]==mx && s[n-1]==mn && count(s.begin(),s.end(),mx)==1 && count(s.begin(),s.end(),mn)==1)return 3;
        return 2;
    }
};