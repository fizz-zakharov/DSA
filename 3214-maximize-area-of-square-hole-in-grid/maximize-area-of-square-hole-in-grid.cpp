class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int p=hBars.size();
        int q=vBars.size();
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int x=1,y=1;
        int temp=1,cur=0;
        for(int i=0;i<p;i++){
            if(hBars[i]==cur+1){
                temp++;
                x=max(x,temp);
            }
            else temp=1;
            cur=hBars[i];
        }
        temp=1,cur=0;
        for(int i=0;i<q;i++){
            if(vBars[i]==cur+1){
                temp++;
                y=max(y,temp);
            }
            else temp=1;
            cur=vBars[i];
        }
        return (min(x,y)+1)*(min(x,y)+1);
    }
};