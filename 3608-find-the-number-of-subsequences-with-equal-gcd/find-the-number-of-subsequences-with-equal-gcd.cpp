class Solution {
private:
    long long MOD=1e9+7;
    inline static int dp[200][201][201][2][2];
    inline static int stamp[200][201][201][2][2];
    inline static int curStamp = 0;
    inline static int gcdTable[201][201];
    inline static bool gcdComputed=false;

    void buildGcdTable(){
        for(int a=0;a<=200;a++){
            for(int b=0;b<=200;b++){
                int x=a,y=b;
                while(y!=0){
                    int temp=y;
                    y=x%y;
                    x=temp;
                }
                gcdTable[a][b]=x;
            }
        }
        gcdComputed=true;
    }

    int fn(int i,int j,int k,int x,int y,vector<int>&v){
        if(i<0){
            if(j==k)return 1;
            return 0;
        }
        if(stamp[i][j][k][x][y]==curStamp) return dp[i][j][k][x][y];
        stamp[i][j][k][x][y]=curStamp; // mark visited before recursing (memo semantics)

        int a=fn(i-1,j,k,x,y,v);
        if(x==1){
            a=(a+fn(i-1,gcdTable[j][v[i]],k,x,y,v))%MOD;
        }
        else{
            a=(a+fn(i-1,v[i],k,1,y,v))%MOD;
        }

        if(y==1){
            a=(a+fn(i-1,j,gcdTable[k][v[i]],x,y,v))%MOD;
        }
        else{
            a=(a+fn(i-1,j,v[i],x,1,v))%MOD;
        }

        return dp[i][j][k][x][y] = a;
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        if(!gcdComputed) buildGcdTable();
        curStamp++; // "clears" dp in O(1) instead of memset
        return fn(n-1,0,0,0,0,nums)-1;
    }
};