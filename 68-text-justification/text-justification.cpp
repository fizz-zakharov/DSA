class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n=words.size();
        int c=0;
        int cur=0;
        int j=0;
        for(int i=0;i<n;i++){
            c+=words[i].size();
            cur++;
            if(c+cur-1>maxWidth){
                c-=words[i].size();
                cur--;
                string temp;
                if(cur==1){
                    temp+=words[j];
                    int rem=maxWidth-temp.size();
                    string add(rem,' ');
                    temp+=add;
                    ans.push_back(temp);
                    cur=0;
                    c=0;
                    j=i;
                    i--;
                    continue;
                }
                int space=(maxWidth-c)/(cur-1);
                int extra=0;
                if((maxWidth-c)%(cur-1)!=0){
                    extra+=(maxWidth-c)%(cur-1);
                }
                string add(space,' ');
                for(int k=j;k<i;k++){
                    temp+=words[k];
                    if(k<i-1){
                        temp+=add;
                        if(extra){
                            temp.push_back(' ');
                            extra--;
                        }
                    }
                }
                ans.push_back(temp);
                c=words[i].size();
                cur=1;
                j=i;
            }
        }
        string temp;
        
        for(int k=j;k<n;k++){
            temp+=words[k];
            if(k<n-1)temp.push_back(' ');
        }
        int space=maxWidth-temp.size();
        if(space>0){
            string add(space,' ');
            temp+=add;
        }
        
        ans.push_back(temp);
        return ans;

    }
};