class Solution {
public:
    const long long MOD=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        string temp;
        vector<int> ind;
        vector<int> pre(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            if(s[i]!='0'){
                temp.push_back(s[i]);
                ind.push_back(i);
            }
            sum=(sum+s[i]-'0')%MOD;
            pre[i]=sum;
        }

        int m=temp.size();
        vector<long long> numpre(m+1,0); 
        vector<long long> pw(m+1,1);
        for(int i=0;i<m;i++){
            numpre[i+1]=(numpre[i]*10+(temp[i]-'0'))%MOD;
            pw[i+1]=(pw[i]*10)%MOD;
        }

        vector<int> ans;
        for(auto it:queries){
            int l=it[0];
            int r=it[1];
            auto li = lower_bound(ind.begin(),ind.end(),l);
            auto ri = upper_bound(ind.begin(),ind.end(),r);

            if(li==ri){
                ans.push_back(0); 
                continue;
            }

            int lind=li-ind.begin();
            int rind=(ri-ind.begin())-1;

            int len=rind-lind+1;
            long long x = ((numpre[rind+1] - numpre[lind]*pw[len])%MOD+MOD)%MOD;

            int presum;
            if(l==0)presum=pre[r];
            else presum=pre[r]-pre[l-1];

            long long val=((x%MOD)*1LL*presum)%MOD;
            ans.push_back((int)val);
        }
        return ans;
    }
};