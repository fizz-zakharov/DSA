class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> suff(n+1,0);
        int j=m-1;
        for(int i=n-1;i>=0;i--){
            if(j>=0 && word1[i]==word2[j]){
                j--;
            }
            suff[i]=m-j-1;
        }

        bool ch=false;
        j=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(j<m && word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(!ch && j<m && suff[i+1]>=m-j-1){
                ans.push_back(i);
                j++;
                ch=true;
            }
        }
        if(j>=m)return ans;
        return {};
    }
};