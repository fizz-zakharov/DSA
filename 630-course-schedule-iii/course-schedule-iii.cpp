class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        sort(courses.begin(),courses.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];
        });
        int c=0;
        int ans=0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            int duration=courses[i][0];
            int limit=courses[i][1];
            if(c+duration<=limit){
                ans++;
                c+=duration;
                pq.push(duration);
            }
            else{
                if(!pq.empty() && pq.top()>duration){
                    c=c-pq.top()+duration;
                    pq.pop();
                    pq.push(duration);
                }
            }
        }
        return ans;
    }
};