class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int i=1,j=n-2;
        int temp=arr[n-1];
        while(j>=0 && temp>=arr[j]){
            temp=arr[j];
            j--;
        }
        j++;
        if(j==0)return 0;
        int ans=j;
        for(int i=0;i<n;i++){
            if(i>0 && arr[i]<arr[i-1])break;
            if(j>=n){
                ans=min(ans,n-i-1);
            }
            else if(arr[i]<=arr[j]){
                ans=min(ans,j-i-1);
            }
            else{
                j++;
                i--;
            }
        }
        return ans;

    }
};