class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size();
        int m=part.size();
        string temp=s;
        while(true){
            bool ch=false;
            //cout<<temp<<'\n';
            for(int i=0;i<temp.size();i++){
                if(i+m-1<temp.size()){
                    //cout<<temp.substr(i,m)<<'\n';
                    if(temp.substr(i,m)==part){
                        ch=true;
                        string l;
                        string r;
                        if(i>0){
                            l=temp.substr(0,i);
                        }
                        if(i+m<temp.size()){
                            r=temp.substr(i+m,temp.size()-(i+m-1));
                        }
                        temp=l+r;
                        break;
                    }
                }
            }
            if(!ch)break;
        }
        return temp;
    }
};