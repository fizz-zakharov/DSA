class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        string ans;
        map<char,int> m;
        for(int i=0;i<n/2;i++)m[s[i]]++;
        for(auto it:m){
            for(int j=0;j<it.second;j++){
                ans.push_back(it.first);
            }
        }
        string temp=ans;
        reverse(temp.begin(),temp.end());
        if(n&1)ans.push_back(s[n/2]);
        ans+=temp;
        return ans;
    }
};