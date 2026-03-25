class Solution {
private:
    int fn(int i,int w,int l,int h,vector<vector<int>>&v){
        if(i>=v.size())return 0;

        int a=v[i][0];
        int b=v[i][1];
        int c=v[i][2];

        int ans=0;
        //skip current cuboid;
        ans=fn(i+1,w,l,h,v);

        //take
        if (a >= w && b >= l && c>=h)ans = max(ans, c + fn(i+1, a, b, c, v));

        return ans;

    }
public:
    int maxHeight(vector<vector<int>>& cuboids){
        int n=cuboids.size();
        
        for(auto &it:cuboids){
            sort(it.begin(),it.end());
        }
        sort(cuboids.begin(),cuboids.end());

        return fn(0,0,0,0,cuboids);
    }
};