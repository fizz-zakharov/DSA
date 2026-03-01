class Solution {
public:
    int minPartitions(string n) {
        int c=0;
        for(int i=0;i<n.size();i++){
            int k=n[i]-'0';
            c=max(c,k);
        }
        return c;
    }
};