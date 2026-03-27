class Solution {
private:
    void leftshift(vector<int>&v){
        int n=v.size();
        vector<int> t;
        for(int i=1;i<n;i++)t.push_back(v[i]);
        t.push_back(v[0]);
        v=t;
    }
    void rightshift(vector<int>&v){
        int n=v.size();
        vector<int> t;
        t.push_back(v[n-1]);
        for(int i=0;i<n-1;i++)t.push_back(v[i]);
        v=t;
    }
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> temp=mat;
        while(k--){
            for(int i=0;i<m;i++){
                if(i&1)rightshift(temp[i]);
                else leftshift(temp[i]);
            }
        }
        if(temp==mat)return true;
        return false;
    }
};