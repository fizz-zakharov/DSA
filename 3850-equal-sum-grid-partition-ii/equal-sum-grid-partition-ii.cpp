class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long m=grid.size();
        long long n=grid[0].size();
        vector<long long> prerow(n),suffrow(n);
        vector<long long> precol(m),suffcol(m);

        vector<vector<pair<int,int>>> ind(1e5+1);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ind[grid[i][j]].push_back({i,j});
            }
        }


        //row
        for(long long j=0;j<n;j++){
            long long prefix=0;
            for(long long i=0;i<m;i++){
                prefix+=grid[i][j];
            }
            prerow[j]=prefix;
        }
        long long sum=0;
        for(long long i=0;i<n;i++){
            sum+=prerow[i];
            prerow[i]=sum;
        }
        suffrow[n-1]=0;
        for(long long j=n-1;j>=0;j--){
            long long suffix=0;
            for(long long i=0;i<m;i++){
                suffix+=grid[i][j];
            }
            if(j>0)suffrow[j-1]=suffix;
        }
        sum=0;
        for(long long i=n-1;i>=0;i--){
            sum+=suffrow[i];
            suffrow[i]=sum;
        }


        //column
        for(long long i=0;i<m;i++){
            long long prefix=0;
            for(long long j=0;j<n;j++){
                prefix+=grid[i][j];
            }
            precol[i]=prefix;
        }
        sum=0;
        for(long long i=0;i<m;i++){
            sum+=precol[i];
            precol[i]=sum;
        }
        suffcol[m-1]=0;
        for(long long i=m-1;i>=0;i--){
            long long suffix=0;
            for(long long j=0;j<n;j++){
                suffix+=grid[i][j];
            }
            if(i>0)suffcol[i-1]=suffix;
        }
        sum=0;
        for(long long i=m-1;i>=0;i--){
            sum+=suffcol[i];
            suffcol[i]=sum;
        }

        for(long long i=0;i<m;i++){
            if(precol[i]==suffcol[i])return true;
            else{
                long long val=abs(precol[i]-suffcol[i]);
                if(val>1e5)continue;

                if(precol[i]>suffcol[i]){
                    for(auto it:ind[val]){
                        if(it.first<=i){
                            //block 1
                            if(i+1>1&&n-1>1)return true;
                            else{
                                if((it.first==0&&it.second==0)||(it.first==m-1&&it.second==n-1))return true;
                                if(it.first==0&&it.second>0){
                                    if(it.second==0||it.second==i)return true;
                                }
                                if(it.first>0&&it.second==0){
                                    if(it.first==0||it.first==i)return true;
                                }
                            }
                        }
                    }
                }
                else{
                    for(auto it:ind[val]){
                        if(it.first>i){
                            //block 2
                            if(m-i-1>1&&n-1>1)return true;
                            else{
                                if((it.first==0&&it.second==0)||(it.first==m-1&&it.second==n-1))return true;
                                if(it.first+1==1&&it.second+1>1){
                                    if(it.second==i+1||it.second==n-1)return true;
                                }
                                if(it.first+1>1&&it.second+1==1){
                                    if(it.first==0||it.first==m-1)return true;
                                }
                            }
                        }
                    }
                }
            }
        }

        for(long long i=0;i<n;i++){
            if(prerow[i]==suffrow[i])return true;
            else{
                long long val=abs(prerow[i]-suffrow[i]);
                if(val>1e5)continue;
                if(prerow[i]>suffrow[i]){
                    for(auto it:ind[val]){
                        if(it.second<=i){
                            //block 3
                            if(i+1>1&&m-1>1)return true;
                            else{
                                if((it.first==0&&it.second==0)||(it.first==m-1&&it.second==n-1))return true;
                                if(it.first+1==1&&it.second+1>1){
                                    if(it.second==0||it.second==i)return true;
                                }
                                if(it.first+1>1&&it.second+1==1){
                                    if(it.first==0||it.first==m-1)return true;
                                }
                            }
                        }
                    }
                }
                else{
                    for(auto it:ind[val]){
                        if(it.second>i){
                            //block 4
                            if(n-i-1>1&&m-1>1)return true;
                            else{
                                if((it.first==0&&it.second==0)||(it.first==m-1&&it.second==n-1))return true;
                                if(it.first+1==1&&it.second+1>1){
                                    if(it.second==i+1||it.second==n-1)return true;
                                }
                                if(it.first+1>1&&it.second+1==1){
                                    if(it.first==0||it.first==m-1)return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};