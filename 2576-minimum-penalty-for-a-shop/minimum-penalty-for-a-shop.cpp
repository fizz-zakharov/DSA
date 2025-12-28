class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> pre(n);
        vector<int> suff(n+1,0);
        int sum=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='N')sum++;
            pre[i]=sum;
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            if(customers[i]=='Y')sum++;
            suff[i]=sum;
        }
        int temp=suff[0];
        int ind=0;
        for(int i=1;i<=n;i++){
            if(suff[i]+pre[i-1]<temp){
                temp=suff[i]+pre[i-1];
                ind=i;
            }
        }
        return ind;
    }
};