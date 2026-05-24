class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ind=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                ind=i;
                break;
            }
        }
        if(ind==0){
            if(nums.size()==1)return 0;
            bool inc=true;
            bool dec=true;

            //inc case
            int temp=0;
            for(int i=1;i<n;i++){
                if(nums[i]<temp){
                    inc=false;
                    break;
                }
                temp=nums[i];
            }

            //dec case
            temp=n;
            for(int i=1;i<n;i++){
                if(nums[i]>temp){
                    dec=false;
                    break;
                }
                temp=nums[i];
            }
            if(inc)return 0;
            if(dec)return 2;
            return -1;
        }
        if(ind==n-1){
            bool inc=true;
            bool dec=true;

            //inc case
            int temp=0;
            for(int i=0;i<n-1;i++){
                if(nums[i]<temp){
                    inc=false;
                    break;
                }
                temp=nums[i];
            }

            //dec case
            temp=n;
            for(int i=0;i<n-1;i++){
                if(nums[i]>temp){
                    dec=false;
                    break;
                }
                temp=nums[i];
            }
            if(inc)return min(n-1,3);
            if(dec)return 1;
            return -1;
        }
        
        if(nums[ind-1]==n-1 && nums[ind+1]==1){
            //left inc right inc case
            bool linc=true;
            bool riinc=true;
            int temp=n;
            for(int i=ind-1;i>=0;i--){
                if(nums[i]>temp){
                    return -1;
                }
                temp=nums[i];
            }
            temp=0;
            for(int i=ind+1;i<n;i++){
                if(nums[i]<temp){
                    return -1;
                }
                temp=nums[i];
            }
            return min(ind,2+n-ind);
        }
        if(nums[ind-1]==1 && nums[ind+1]==n-1){
            //left dec right dec case
            bool ldec=true;
            bool rdec=true;
            int temp=0;
            for(int i=ind-1;i>=0;i--){
                if(nums[i]<temp){
                    return -1;
                }
                temp=nums[i];
            }
            temp=n;
            for(int i=ind+1;i<n;i++){
                if(nums[i]>temp){
                    return -1;
                }
                temp=nums[i];
            }
            return min(ind+2,n-ind);

        }
        return -1;

    }
};