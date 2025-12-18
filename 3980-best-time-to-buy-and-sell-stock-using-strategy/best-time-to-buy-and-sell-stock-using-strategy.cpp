class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<long long> preprofit(n+1), preprices(n+1);

        for(int i=0;i<n;i++){
            preprofit[i+1] = preprofit[i] + 1LL * prices[i] * strategy[i];
            preprices[i+1] = preprices[i] + prices[i];
        }

        long long ans = preprofit[n];
        int h = k/2;

        for(int i=0; i+k<=n; i++){
            int L1 = i,R1 =i+h-1;      
            int L2 = i+h,R2 = i+k-1;       

            long long windowProfit = preprofit[R2+1] - preprofit[L1];
            long long secondHalfPrices = preprices[R2+1] - preprices[L2];
            long long gain = secondHalfPrices - windowProfit;

            ans = max(ans, preprofit[n] + gain);
        }

        return ans;
    }
};
