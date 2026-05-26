class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        map<char,int> m1,m2;
        for(int i=0;i<n;i++){
            if(word[i]<97)m1[word[i]]++;
            else m2[word[i]]++;
        }
        int ans=0;
        for(auto it:m1){
            if(m2[it.first+32]>0)ans++;
        }
        return ans;
    }
};