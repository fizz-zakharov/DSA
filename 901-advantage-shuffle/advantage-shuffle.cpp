class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        vector<int> ans(n);
        vector<int> copy = nums2;

        sort(nums1.begin(), nums1.end());
        sort(copy.begin(), copy.end());

        map<int, vector<int>> m;
        stack<int> s;

        int i=0,j=0;

        while(i<n){
            if(nums1[i] > copy[j]){
                m[copy[j]].push_back(nums1[i]);
                j++;
            } 
            else{
                s.push(nums1[i]);
            }
            i++;
        }

        for(int i = 0; i < n; i++){
            if (!m[nums2[i]].empty()){
                ans[i] = m[nums2[i]].back();
                m[nums2[i]].pop_back();
            } 
            else{
                ans[i] = s.top();
                s.pop();
            }
        }

        return ans;
    }
};