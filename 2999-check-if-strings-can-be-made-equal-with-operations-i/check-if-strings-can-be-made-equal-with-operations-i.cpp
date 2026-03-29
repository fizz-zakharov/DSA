class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string t1;
        string t2;
        string t3;
        string t4;
        for(int i=0;i<4;i++){
            if(i&1){
                t1.push_back(s1[i]);
                t2.push_back(s2[i]);
            }
            else{
                t3.push_back(s1[i]);
                t4.push_back(s2[i]);
            }
        }
        sort(t1.begin(),t1.end());
        sort(t2.begin(),t2.end());
        sort(t3.begin(),t3.end());
        sort(t4.begin(),t4.end());
        if(t1==t2&&t3==t4)return true;
        return false;
    }
};