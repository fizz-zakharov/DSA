class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        vector<int> diff(n+1,0);
        int sum=0;
        sum+=target[0];
        diff[0]=sum;
        for(int i=1;i<n;i++){
            diff[i]=target[i]-sum;
            sum+=diff[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(diff[i]>0)ans+=diff[i];
        }
        return ans;

    }
};