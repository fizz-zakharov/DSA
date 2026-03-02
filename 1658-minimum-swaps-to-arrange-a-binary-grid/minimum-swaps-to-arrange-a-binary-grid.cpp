class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        int c=0;
        for(int i=0;i<n-1;i++){
            bool check=false;
            for(int j=i+1;j<n;j++){
                if(grid[i][j]){
                    check=true;
                }
            }
            if(check){ //row is not in the right place and we'll find if the right row exists?
                bool exists=false;
                for(int k=i+1;k<n;k++){
                    bool valid=true;
                    for(int j=i+1;j<n;j++){ //check if we have got the correct row
                        if(grid[k][j]){
                            valid=false;
                        }
                    }
                    if(valid){ //if the correct row then swap to the correct position
                        exists=true;
                        for(int p=k;p>i;p--){
                            swap(grid[p],grid[p-1]);
                            c++;
                        }
                        break;
                    }
                }
                if(!exists)return -1; //if we never got the correct row
            }
        }
        return c;
    }
};