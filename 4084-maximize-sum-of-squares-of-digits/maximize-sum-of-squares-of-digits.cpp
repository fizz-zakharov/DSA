class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans;
        int n=sum/9;
        int rest=sum%9;
        int g=n;
        if(rest>0 && n+1>num)return "";
        if(n>num)return "";
        while(n--){
            ans.push_back('9');
        }
        bool k=false;
        if(rest){
            char ch=rest+'0';
            ans.push_back(ch);
            k=true;
        }
        if(k)g++;
        if(g<num){
            int t=num-g;
            while(t--){
                ans.push_back('0');
            }
        }
        return ans;
    }
};