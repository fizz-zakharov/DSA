class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        int ans=0;
        set<int> s;
        for(int i=0;i<n;i++){
            string temp;
            if(digits[i]==0)continue;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                for(int k=0;k<n;k++){
                    if(k==i||k==j)continue;
                    if(digits[k]%2==0){
                        s.insert(100*digits[i]+10*digits[j]+digits[k]);
                    }
                }
            }
        }
        return s.size();
    }
};