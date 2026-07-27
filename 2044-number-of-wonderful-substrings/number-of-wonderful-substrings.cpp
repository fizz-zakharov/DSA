class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n=word.size();
        long long freq[1024]={0};
        int mask=0;
        long long ans=0;
        freq[0]=1;
        for(int i=0;i<n;i++){
            int k=word[i]-'a';
            mask=(mask)^(1<<k);
            ans+=freq[mask];
            for(int j=0;j<10;j++){
                ans+=freq[mask^(1<<j)];
            }
            freq[mask]++;
        }
        return ans;
    }
};