class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i=0,j=1;
        int sum=numbers[i]+numbers[j];
        while(true){
            if(sum==target){
                return {i+1,j+1};
            }
            while(sum<target){
                if(j==n-1)break;
                sum-=numbers[j];
                j++;
                sum+=numbers[j];
            }
            if(sum==target){
                return {i+1,j+1};
            }
            if(sum>target || j==n-1){
                sum-=numbers[i];
                i++;
                sum+=numbers[i];
                while(sum>target){
                    sum-=numbers[j];
                    j--;
                    sum+=numbers[j];
                }
            }
        }
        return {0,0};
    }
};