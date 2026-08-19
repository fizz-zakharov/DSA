class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m=reservedSeats.size();
        if(m==0)return 2*n;
        sort(reservedSeats.begin(),reservedSeats.end());
        int c=0;
        int start=reservedSeats[0][0];
        vector<int> temp(10,0);
        int ans=0;
        int k=1;
        temp[reservedSeats[0][1]-1]=1;
        for(int i=1;i<m;i++){
            if(reservedSeats[i][0]==start){
                temp[reservedSeats[i][1]-1]=1;
                k++;
            }
            else{
                /*for(int j=0;j<10;j++){
                    cout<<temp[j]<<" ";
                }
                */
                cout<<'\n';
                bool ch=false;
                if(temp[1]==0 && temp[2]==0 && temp[3]==0 && temp[4]==0){
                    ans++;
                    ch=true;
                }
                if(temp[5]==0 && temp[6]==0 && temp[7]==0 && temp[8]==0){
                    ans++;
                    ch=true;
                }
                if(!ch && temp[3]==0 && temp[4]==0 && temp[5]==0 && temp[6]==0)ans++;
                c++;
                start=reservedSeats[i][0];
                fill(temp.begin(),temp.end(),0);
                temp[reservedSeats[i][1]-1]=1;
                k=1;
            }
        }
       bool ch=false;
        if(temp[1]==0 && temp[2]==0 && temp[3]==0 && temp[4]==0){
            ans++;
            ch=true;
        }
        if(temp[5]==0 && temp[6]==0 && temp[7]==0 && temp[8]==0){
            ans++;
            ch=true;
        }
        if(!ch && temp[3]==0 && temp[4]==0 && temp[5]==0 && temp[6]==0)ans++;
        c++;
        ans += (n-c)*2;
        return ans;
    }
};