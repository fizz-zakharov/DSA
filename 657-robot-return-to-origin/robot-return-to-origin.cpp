class Solution {
public:
    bool judgeCircle(string moves) {
        int n=moves.size();
        int a=0;
        int b=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='R')a++;
            if(moves[i]=='L')a--;
            if(moves[i]=='U')b++;
            if(moves[i]=='D')b--;
        }
        if(a==0&&b==0)return true;
        return false;
    }
};