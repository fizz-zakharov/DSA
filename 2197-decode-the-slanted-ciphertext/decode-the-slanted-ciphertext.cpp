class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size();
        int col=n/rows;
        vector<vector<char>> mat(rows,vector<char>(col,'*'));
        int c=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                mat[i][j]=encodedText[c];
                c++;
            }
        }
        string ans;
        for(int k=0;k<col;k++){
            int i=0;
            int j=k;
            while(i<rows&&j<col){
                ans.push_back(mat[i][j]);
                i++;
                j++;
            }
        }
        int sz=ans.size();
        for(int i=sz-1;i>=0;i--){
            if(ans[i]==' ')ans.pop_back();
            else break;
        }
        return ans;
    }
};