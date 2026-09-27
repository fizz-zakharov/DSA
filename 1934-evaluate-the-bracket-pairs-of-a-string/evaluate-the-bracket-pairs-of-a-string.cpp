class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.size();
        map<string,string> m;
        for(auto it:knowledge){
            m[it[0]]=it[1];
        }
        string ans;
        int start=0;
        for(int i=0;i<n;i++){
            if(s[i]==')')i++;
            if(i>=n)break;
            start=i;
            bool ch=false;
            int len=0;
            while(i<n && s[i]!='('){
                len++;
                i++;
                ch=true;
            }
            if(ch){
                i--;
                ans+=(s.substr(start,len));
            }
            else{
                i++;
                start=i;
                while(i<n && s[i]!=')'){
                    len++;
                    i++;
                }
                i--;
                string temp=s.substr(start,len);
                //cout<<temp<<'\n';
                if(m.find(temp)!=m.end()){
                    ans+=m[temp];
                }
                else ans.push_back('?');
            }
        }
        return ans;
    }
};