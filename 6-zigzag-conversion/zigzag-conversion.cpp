class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows==1)return s;
        vector<vector<char>> v(numRows,vector<char>(n,'#'));

        int i=0,j=0,k=0;
        while(i<numRows && k<n){
            v[i][j]=s[k];
            if(i==numRows-1){
                k++;
                while(k<n && i!=0){
                    i--;
                    j++;
                    v[i][j]=s[k];
                    k++;
                }
                i++;
                continue;
            }
            i++;
            k++;
        }
        string ans;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]!='#')ans.push_back(v[i][j]);
            }
        }
        return ans;
    }
};