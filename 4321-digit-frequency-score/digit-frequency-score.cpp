class Solution {
public:
    int digitFrequencyScore(int n) {
        map<int,int> m;
        while(n){
            int temp=n%10;
            m[temp]++;
            n/=10;
        }
        int ans=0;
        for(auto it:m){
            ans+=it.first*it.second;
        }
        return ans;
    }
};