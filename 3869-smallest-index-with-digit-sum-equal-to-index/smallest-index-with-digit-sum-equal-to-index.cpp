class Solution {
private:
    int sumofdigits(int num){
        int sum=0;
        while(num){
            int temp=num%10;
            sum+=temp;
            num=num/10;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(sumofdigits(nums[i])==i)return i;
        }
        return -1;
    }
};