class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.size();
        unordered_map<char,int> m;
        for(int i=0;i<n;i++)m[text[i]]++;
        int ans=min({m['b'],m['a'],m['l']/2,m['o']/2,m['n']});
        return ans;
    }
};