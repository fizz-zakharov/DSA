class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<long long,long long> m;
        unordered_map<long long,long long> m2;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        set<vector<int>> ans;
        long long sum=0;
        vector<int> temp;
        for(int i=0;i<n;i++){
            m2[nums[i]]++;
            sum+=nums[i];
            temp.push_back(nums[i]);
            for(int j=i+1;j<n;j++){
                m2[nums[j]]++;
                sum+=nums[j];
                temp.push_back(nums[j]);
                for(int k=j+1;k<n;k++){
                    m2[nums[k]]++;
                    sum+=nums[k];
                    temp.push_back(nums[k]);
                    long long rem = (long long)target - sum;
                    if (rem >= nums[k] && m.find(rem) != m.end() && m[rem] > m2[rem]) {
                        temp.push_back((int)rem);
                        ans.insert(temp);
                        temp.pop_back();
                    }
                    temp.pop_back();
                    sum-=nums[k];
                    m2[nums[k]]--;
                }
                temp.pop_back();
                sum-=nums[j];
                m2[nums[j]]--;
            }
            temp.pop_back();
            sum-=nums[i];
            m2[nums[i]]--;
        }
        vector<vector<int>> res;
        for(auto it:ans)res.push_back(it);
        return res;
    }
};