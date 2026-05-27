class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        map<char,int> m;
        map<char,int> ch; //0-> a, 1-> aA
        int ans=0;
        for(int i=0;i<n;i++){
            if(ch[word[i]]==2)continue; //aAaa
            if(ch[word[i]]==1){ //aAa
                ans--;
                ch[word[i]]=2;
                continue;
            }
            if(ch[word[i]+32]<1 && m[word[i]+32]>0){ //aA
                ans++; 
                ch[word[i]+32]=1; //a->X
            }
            if(m[word[i]-32]>0){ //Aa
                ch[word[i]]=2;
            }
            m[word[i]]++;
        }
        return ans;
    }
};