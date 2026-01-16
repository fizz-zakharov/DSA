class Solution {
    long long MOD = 1e9 + 7;
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int p = hFences.size();
        int q = vFences.size();
        unordered_set<int> s1;
        unordered_set<int> s2;
        s1.reserve(200000);
        s2.reserve(200000);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        hFences.insert(hFences.begin(), 1);
        hFences.push_back(m);
        vFences.insert(vFences.begin(), 1);
        vFences.push_back(n);

        p += 2;
        q += 2;

        for (int i = 0; i < p - 1; i++) {
            for (int j = i + 1; j < p; j++) {
                s1.insert(hFences[j] - hFences[i]);
            }
        }

        long long side = 0;
        bool check = false;

        for(int i=0;i<q-1;i++){
            for(int j=i+1;j<q;j++){
                int diff = vFences[j] - vFences[i];
                if(s1.count(diff)){
                    side = max(side,(long long)diff);
                    check = true;
                }
            }
        }

        if (check) return (side * side) % MOD;
        return -1;
    }
};
