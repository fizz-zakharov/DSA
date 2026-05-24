class Solution {
public:
    int passwordStrength(string password) {
        int n=password.size();
        set<char> s;
        for(int i=0;i<n;i++){
            s.insert(password[i]);
        }
        int ans=0;
        for(auto it:s){
            if(it>='a'&&it<='z')ans+=1;
            else if(it>='A'&&it<='Z')ans+=2;
            else if(it>='0'&&it<='9')ans+=3;
            else ans+=5;
        }
        return ans;
    }
};