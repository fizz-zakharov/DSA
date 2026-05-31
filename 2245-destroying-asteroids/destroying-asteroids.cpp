class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n=asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        long long s=mass;
        for(int i=0;i<n;i++){
            if(s>=asteroids[i]){
                s+=asteroids[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
};