class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;   // all distinct ORs
        unordered_set<int> prev;  // ORs of subarrays ending at previous index
        
        for (int x : arr) {
            unordered_set<int> curr;
            
            curr.insert(x);
            
            for (int y : prev)
                curr.insert(y | x);
            
            for (int val : curr)
                ans.insert(val);
            
            prev = curr;
        }
        
        return ans.size();
    }
};
