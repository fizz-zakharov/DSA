class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(colors[i]!=colors[j]){
                    ans=max(ans,i-j);
                }
            }
        }
        return ans;
    }
};