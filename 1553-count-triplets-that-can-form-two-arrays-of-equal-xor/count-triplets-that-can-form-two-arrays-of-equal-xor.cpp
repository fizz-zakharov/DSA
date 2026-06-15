class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        map<int,vector<int>> m;
        m[0]={-1};
        vector<int> prexor(n,0);
        int x=0;
        int ans=0;
        for(int i=0;i<n;i++){
            x=x^arr[i];
            prexor[i]=x;
            if(m.find(prexor[i])!=m.end()){
                for(auto it:m[prexor[i]]){
                    ans+=i-it-1;
                }
            }
            m[prexor[i]].push_back(i);
        }
        return ans;
    }
};