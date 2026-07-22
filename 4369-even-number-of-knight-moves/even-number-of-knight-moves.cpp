class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int s=start[0]+start[1];
        int e=target[0]+target[1];
        if((s%2==0 && e%2==0) || (s&1 && e&1))return true;
        return false;

    }
};