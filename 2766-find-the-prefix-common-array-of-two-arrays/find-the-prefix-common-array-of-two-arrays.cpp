class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        map<int,int> m;
        vector<int> ans(n);
        int c=0;
        for(int i=0;i<n;i++){
            m[A[i]]++;
            m[B[i]]++;
            if(A[i]==B[i])c+=m[A[i]]/2;
            else c+=m[A[i]]/2 + m[B[i]]/2;
            ans[i]=c;
        }
        return ans;
    }
};