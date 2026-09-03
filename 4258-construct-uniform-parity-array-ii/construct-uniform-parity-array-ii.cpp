class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        sort(nums1.begin(),nums1.end());
        int first_odd=-1;
        int first_even=-1;
        bool all_odd=true;
        bool all_even=true;
        for(int i=0;i<n;i++){
            if(nums1[i]&1){
                if(first_odd==-1){
                    first_odd=nums1[i];
                }
                else continue;
            }
            else{
                if(first_odd==-1)all_odd=false;
                continue;
            }
        }

        for(int i=0;i<n;i++){
            if(nums1[i]&1)all_even=false;
        }
        return (all_odd||all_even);
    }
};