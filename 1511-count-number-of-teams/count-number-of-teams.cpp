class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int left_less=0;
            int left_greater=0;
            int right_less=0;
            int right_greater=0;
            for(int j=i-1;j>=0;j--){
                if(rating[j]<rating[i])left_less++;
                else left_greater++;
            }
            for(int j=i+1;j<n;j++){
                if(rating[j]<rating[i])right_less++;
                else right_greater++;
            }
            ans+=left_less*right_greater + left_greater*right_less; 
        }
        return ans;
    }
    
};