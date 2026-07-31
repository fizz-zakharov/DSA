class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        vector<int> diff(n);
        int cur=heights[0];
        diff[0]=0;
        for(int i=0;i<n;i++){
            if(heights[i]<=cur){
                cur=heights[i];
                continue;
            }
            else{
                diff[i]=heights[i]-cur;
                cur=heights[i];
            }
        }
        for(int i=0;i<n;i++){
            cout<<diff[i]<<' ';
        }
        cout<<'\n';
        priority_queue<int,vector<int>,greater<int>> pq;
        int ans=-1;
        for(int i=0;i<n;i++){
            cout<<"bricks: "<<bricks<<" "<<"ladders: "<<ladders<<'\n';
            if(diff[i]!=0){
                if(ladders>0){
                    pq.push(diff[i]);
                    ladders--;
                }
                else{
                    if(!pq.empty() && pq.top()<diff[i]){
                        if(bricks>=pq.top()){
                            bricks-=pq.top();
                            pq.pop();
                            pq.push(diff[i]);
                        }
                        else break;
                    }
                    
                    else{
                        if(bricks>=diff[i]){
                            bricks-=diff[i];
                        }
                        else break;
                    }
                }
            }
            ans=i;
        }
        return ans;
    }
};