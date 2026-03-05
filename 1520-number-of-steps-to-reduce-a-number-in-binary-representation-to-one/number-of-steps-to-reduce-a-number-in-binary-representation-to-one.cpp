class Solution {
public:
    int numSteps(string s) {
        int ct = 0;
        int c = 0;

        for(int i = s.size() - 1; i > 0; i--){
            int bit = (s[i] - '0') + c;
            if(bit == 1){
                ct += 2;   
                c = 1;
            } 
            else {
                ct += 1;   
            }
        }

        return ct + c;
    }
};
