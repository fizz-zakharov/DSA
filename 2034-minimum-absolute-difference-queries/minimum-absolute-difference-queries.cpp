class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<vector<int>> pre(n,vector<int>(101,0));
        pre[0][nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<=100;j++){
                pre[i][j]=pre[i-1][j];
            }
            pre[i][nums[i]]++;
        }
        vector<int> ans;
        for(auto it:queries){
            int l=it[0];
            int r=it[1];
            int val=200;
            if(l==0){
                bool ch=false;
                int last=-1;
                for(int j=1;j<=100;j++){
                    if(pre[r][j]>0){
                        if(ch){
                            val=min(val,j-last);
                            last=j;
                        }
                        else{
                            last=j;
                            ch=true;
                        }
                    }
                }
                if(val==200)val=-1;
            }
            else{
                bool ch=false;
                int last=-1;
                for(int j=1;j<=100;j++){
                    if(pre[r][j]-pre[l-1][j]>0){
                        if(ch){
                            val=min(val,j-last);
                            last=j;
                        }
                        else{
                            last=j;
                            ch=true;
                        }
                    }
                }
                if(val==200)val=-1;
            }
            ans.push_back(val);
        }
        return ans;
    }
};