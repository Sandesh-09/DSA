class Solution {
public:
    int seconds(string time){
        int h=stoi(time.substr(0,2));
        int m=stoi(time.substr(3,2));
        int s=stoi(time.substr(6,2));
        return (h*60*60)+(m*60)+s;
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        int start=seconds(startTime);
        int end=seconds(endTime);
        return end-start;
    }
};