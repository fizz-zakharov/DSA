class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int c=0;
                for(int k=0;k<=n-i-1;k++){
                    for(int l=0;l<=n-j-1;l++){
                        if(img1[k][l]==1 && img2[i+k][j+l]==1)c++;
                    }
                }
                ans=max(ans,c);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int c=0;
                for(int k=0;k<=n-i-1;k++){
                    for(int l=0;l<=n-j-1;l++){
                        if(img2[k][l]==1 && img1[i+k][j+l]==1)c++;
                    }
                }
                ans=max(ans,c);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int c=0;
                for(int k=0;k<=n-i-1;k++){
                    for(int l=0;l<=n-j-1;l++){
                        if(img1[k][l+j]==1 && img2[i+k][l]==1)c++;
                    }
                }
                ans=max(ans,c);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int c=0;
                for(int k=0;k<=n-i-1;k++){
                    for(int l=0;l<=n-j-1;l++){
                        if(img2[k][j+l]==1 && img1[i+k][l]==1)c++;
                    }
                }
                ans=max(ans,c);
            }
        }
        return ans;
    }
};