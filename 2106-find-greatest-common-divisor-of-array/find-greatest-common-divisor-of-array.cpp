class Solution {
private:
    int gcd(int a,int b){
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return gcd(nums[0],nums[n-1]);
    }
};