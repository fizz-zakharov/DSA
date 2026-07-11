class Solution {
private:
    int ncr(int n,int r){
        if(r>n)return 0;
        int res=1;
        for(int i=1;i<=r;i++){
            res=res*(n-r+i)/i;
        }
        return res;
    }
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int v=destination[0];
        int h=destination[1];
        int c=v+h;
        string ans;
        for(int i=0;i<c;i++){
            if(h>0){
                int com=ncr(v+h-1,h-1);
                if(com>=k){
                    ans.push_back('H');
                    h--;
                }
                else{
                    ans.push_back('V');
                    v--;
                    k-=com;
                }
            }
            else{
                ans.push_back('V');
                v--;
            }
        }
        return ans;
    }
};