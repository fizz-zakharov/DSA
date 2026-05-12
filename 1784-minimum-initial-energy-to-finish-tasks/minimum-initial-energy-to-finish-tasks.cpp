class Solution {
private:
    bool valid(int k,vector<vector<int>>&v){
        int n=v.size();
        for(int i=0;i<n;i++){
            if(k<v[i][1])return false;
            k-=v[i][0];
        }
        if(k<0)return false;
        return true;
    }
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n=tasks.size();
        sort(tasks.begin(),tasks.end(),[](const vector<int>&a,const vector<int>&b){
            int diff1=a[1]-a[0];
            int diff2=b[1]-b[0];
            return diff1>diff2;
        });
        int sum=0;
        for(int i=0;i<n;i++)sum+=tasks[i][0]+tasks[i][1];
        int low=0,high=1e9;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(valid(mid,tasks)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;

    }
};