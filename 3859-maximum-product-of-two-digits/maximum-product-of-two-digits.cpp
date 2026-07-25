class Solution {
public:
    int maxProduct(int n) {
        vector<int> v;
        int temp=n;
        while(temp){
            int x=temp%10;
            v.push_back(x);
            temp=temp/10;
        }
        sort(v.begin(),v.end());
        int s=v.size();
        return v[s-1]*v[s-2];
    }
};