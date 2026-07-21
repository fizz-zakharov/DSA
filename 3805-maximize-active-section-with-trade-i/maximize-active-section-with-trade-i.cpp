class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int c=0;
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(s[i]=='1')c++;
            else{
                int j=i;
                while(j<n && s[j]=='0'){
                    j++;
                }
                j--;
                temp.push_back(j-i+1);
                i=j;
            }
        }
        int ans=INT_MIN;
        if(temp.size()<2)return c;
        for(int i=0;i<=temp.size()-2;i++){
            ans=max(ans,c+temp[i]+temp[i+1]);
        }
        return ans;
    }
};