class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n=commands.size();
        map<pair<int,int>,int> m;
        for(auto it:obstacles){
            m[{it[0],it[1]}]++;
        }
        int dir=1; //dir 1->north,2->east,3->south,4->west cw
        pair<int,int> coordinates={0,0};
        int ans=0;  
        for(int i=0;i<n;i++){
            int x=coordinates.first;
            int y=coordinates.second;
            int k=commands[i];
            if(commands[i]<0){
                if(commands[i]==-2){
                    dir--;
                    if(dir==0)dir=4;
                }
                else{
                    dir++;
                    if(dir==5)dir=1;
                }
            }
            else{
                if(dir==1){
                    for(int step=1;step<=k;step++){  
                        if(m[{x,y+1}]>0)break;      
                        y++;                         
                    }
                }
                if(dir==2){
                    for(int step=1;step<=k;step++){  
                        if(m[{x+1,y}]>0)break;      
                        x++;                          
                    }
                }
                if(dir==3){
                    for(int step=1;step<=k;step++){  
                        if(m[{x,y-1}]>0)break;     
                        y--;                          
                    }
                }
                if(dir==4){
                    for(int step=1;step<=k;step++){  
                        if(m[{x-1,y}]>0)break;     
                        x--;                          
                    }
                }
                coordinates.first=x;
                coordinates.second=y;
                ans=max(ans,x*x+y*y);  
            }
        }
        return ans;  
    }
};