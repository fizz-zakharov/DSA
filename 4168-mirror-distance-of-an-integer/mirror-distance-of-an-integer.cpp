class Solution {
private:
    int rev(int num){
        int digits=0;
        int temp=num;
        while(temp){
            digits++;
            temp=temp/10;
        }
        int ans=0;
        int power=1;
        digits--;
        while(digits--){
            power=power*10;
        }
        while(num){
            int k=num%10;
            ans=ans+k*power;
            power=power/10;
            num=num/10;
        }
        return ans;
    }
public:
    int mirrorDistance(int n) {
        return abs(n-rev(n));
    }
};