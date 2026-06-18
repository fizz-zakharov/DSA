class Solution {
public:
    double angleClock(int hour, int minutes) {
        map<int,double> m;
        int start=1;
        double theta=30;
        m[12]=0;
        while(start<12){
            m[start]=theta;
            start++;
            theta+=30;
        }
        double hourangle=m[hour]+0.5*minutes;
        double minuteangle=6*minutes;
        double diff=abs(hourangle-minuteangle);
        return min(diff,360-diff);

    }
};