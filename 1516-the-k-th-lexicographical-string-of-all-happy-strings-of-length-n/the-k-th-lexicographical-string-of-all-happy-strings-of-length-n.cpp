class Solution {
private:
    void fn(int n,int c,string& s, vector<string>&v){
        if(s.size()==n){
            v.push_back(s);
            return;
        }
        for(int j=0;j<3;j++){
            if(j==c)continue;
            if(j==0){
                s.push_back('a');
                fn(n,0,s,v);
                s.pop_back();
            }
            if(j==1){
                s.push_back('b');
                fn(n,1,s,v);
                s.pop_back();
            }
            if(j==2){
                s.push_back('c');
                fn(n,2,s,v);
                s.pop_back();
            }
        }
        return;

    }
public:
    string getHappyString(int n, int k) {
        string s;
        vector<string> temp;
        fn(n,-1,s,temp);
        if(k>temp.size())return "";
        return temp[k-1];
    }
};