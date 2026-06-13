class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        map<int,char> m;
        char ch='z';
        for(int i=0;i<26;i++){
            m[i]=ch;
            ch--;
        }
        string ans;
        for(auto it:words){
            int count=0;
            for(int i=0;i<it.size();i++){
                count+=weights[it[i]-'a'];
            }
            count=(count)%26;
            ans.push_back(m[count]);
        }
        return ans;
    }
};