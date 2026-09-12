class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n=arr.size();
        map<int,int> left,right;
        int ans=-1;
        vector<int> freq(1e5+2,0);
        for(int i=0;i<n;i++){
            if(left.find(arr[i]-1)!=left.end()){
                freq[right[left[arr[i]-1]]-left[arr[i]-1]+1]--;
                left[arr[i]]=left[arr[i]-1];
                right[left[arr[i]-1]]=arr[i];
                if(right.find(arr[i]+1)!=right.end()){
                    freq[right[arr[i]+1]-left[right[arr[i]+1]]+1]--;
                    right[left[arr[i]-1]]=right[arr[i]+1];
                    left[right[arr[i]+1]]=left[arr[i]];
                    freq[right[left[arr[i]-1]]-left[right[arr[i]+1]]+1]++;
                    left.erase(arr[i]);
                    right.erase(arr[i]+1);

                }
                else{
                    freq[right[left[arr[i]-1]]-left[arr[i]]+1]++;
                }
                left.erase(arr[i]-1);
            }
            else if(right.find(arr[i]+1)!=right.end()){
                freq[right[arr[i]+1]-left[right[arr[i]+1]]+1]--;
                right[arr[i]]=right[arr[i]+1];
                left[right[arr[i]+1]]=arr[i];
                freq[right[arr[i]]-arr[i]+1]++;
                right.erase(arr[i]+1);
            }
            else{
                left[arr[i]]=arr[i];
                right[arr[i]]=arr[i];
                freq[1]++;
            }
            if(freq[m]>0){
                ans=i+1;
            }
        }
        return ans;
    }
};