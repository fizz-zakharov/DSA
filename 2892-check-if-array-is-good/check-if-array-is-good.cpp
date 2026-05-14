class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        for(int i=1;i<=n-1;i++)temp.push_back(i);
        temp.push_back(n-1);
        sort(nums.begin(),nums.end());
        return (nums==temp);

    }
};