class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        map<int,pair<int,char>> m; // pos-> {health,direction}
        for(int i=0;i<n;i++){
            m[positions[i]]={healths[i],directions[i]};
        }
        vector<int> temp=positions;
        sort(positions.begin(),positions.end());
        stack<int> s; //stack of positions
        vector<int> left;
        for(int i=0;i<n;i++){
            int health=m[positions[i]].first;
            char direction=m[positions[i]].second;
            if(direction=='R'){
                s.push(positions[i]);
            }
            else{
                bool alive=false;
                while(!s.empty()){
                    if(m[s.top()].first==health){
                        m[s.top()].first=0;
                        s.pop();
                        health=0;
                        alive=false; //left died
                        break;
                    }
                    if(m[s.top()].first>health){
                        m[s.top()].first--;
                        health=0;
                        alive=false; 
                        break; //current left died
                    }
                    if(m[s.top()].first<health){
                        health--;
                        m[s.top()].first=0;
                        s.pop(); //top right died and left is still alive
                        alive=true;
                    }
                }
                m[positions[i]].first=health;
                if(alive){
                    left.push_back(positions[i]);
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(m[temp[i]].first>0){
                ans.push_back(m[temp[i]].first);
            }
        }
        return ans;
    }
};