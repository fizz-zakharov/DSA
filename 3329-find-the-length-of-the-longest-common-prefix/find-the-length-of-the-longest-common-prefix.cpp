class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        map<string,int> m1;
        map<string,int> m2;
        for(int i=0;i<n;i++){
            string temp=to_string(arr1[i]);
            while(temp.size()){
                m1[temp]++;
                temp.pop_back();
            }
        }
        for(int i=0;i<m;i++){
            string temp=to_string(arr2[i]);
            while(temp.size()){
                m2[temp]++;
                temp.pop_back();
            }
        }
        int ans=0;
        for(auto it:m1){
            string st=it.first;
            if(it.second>0&&m2[st]>0){
                int sz=st.size();
                ans=max(ans,sz);
            }
        }
        return ans;
    }
};