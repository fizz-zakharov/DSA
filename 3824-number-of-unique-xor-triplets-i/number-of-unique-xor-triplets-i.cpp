class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        set<int> s;
        for(int i=1;i<=n;i++)s.insert(i);
        if(n>=3)s.insert(0);
        if(n<3)return s.size();
        for(int i=1;i<n;i++){
            s.insert(i^n);
        }
        return s.size();
    }
};