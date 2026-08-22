class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;
        int temp=n;
        while(temp){
            int cur=temp%10;
            sum+=cur;
            prod*=cur;
            temp=temp/10;
        }
        return (n%(prod+sum)==0);
    }
};