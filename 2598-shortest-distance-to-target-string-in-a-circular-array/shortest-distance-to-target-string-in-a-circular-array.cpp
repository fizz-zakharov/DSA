class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            if(words[i]==target){
                v.push_back(i);
            }
        }
        if(v.size()==0)return -1;
        int ans=INT_MAX;
        for(int i=0;i<v.size();i++){
            int a=abs(startIndex-v[i]);
            int b=startIndex+(n-1-v[i])+1;
            int c=(n-1-startIndex)+v[i]+1;
            ans=min({ans,a,b,c});
        }
        return ans;
    }
};