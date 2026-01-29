class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        map<int,int> m;
        set<vector<int>> s;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
            m[nums[i]]++;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] > 0) break;

            m[nums[i]]--;

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                m[nums[j]]--;

                int need = -nums[i] - nums[j];
                if (m[need] > 0) {
                    vector<int> temp = {nums[i], nums[j], need};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }

                m[nums[j]]++;
            }

            m[nums[i]]++;
        }

        for (auto it : s)
            ans.push_back(it);

        return ans;
    }
};
