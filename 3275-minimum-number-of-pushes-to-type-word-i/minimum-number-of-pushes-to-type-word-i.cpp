class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        unordered_map<char,int> m;
        int start=2;
        int ans=0;
        for(int i=0;i<n;i++){
            if(start==10){
                start=2;
            }
            m[start]++;
            ans+=m[start];
            start++;
        }
        return ans;
    }
};