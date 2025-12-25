class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        sort(happiness.begin(),happiness.end());
        long long ans=0,i=n-1;
        int temp=k,c=0;
        while(temp--){
            ans=max(ans,ans+happiness[i]-c);
            c++;
            i--;
        }
        return ans;
    }
};