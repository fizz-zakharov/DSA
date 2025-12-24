class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n=apple.size();
        int m=capacity.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=apple[i];
        sort(capacity.begin(),capacity.end());
        int ans=0,i=m-1;
        while(sum>0&&i>=0){
            sum-=capacity[i];
            ans++;
            i--;
        }
        return ans;
    }
};