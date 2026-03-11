class Solution {
private:
    string fn(int i, string& s, map<string,int>& m){
        if(i == s.size()){
            if(m.find(s) == m.end()) return s;  
            return "";
        }
        s[i] = '0';
        string left = fn(i + 1, s, m);
        if(left != "") return left;

        s[i] = '1';
        string right = fn(i + 1, s, m);
        if(right != "") return right;

        return "";
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        map<string,int> m;
        for(auto it:nums){
            m[it]++;
        }
        string x;
        for(int i=0;i<nums[0].size();i++){
            x.push_back('0');
        }
        return fn(0,x,m);
    }
};