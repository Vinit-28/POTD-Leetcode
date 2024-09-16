// Problem Link : https://leetcode.com/problems/minimum-time-difference/description/


// Solution //
class Solution {
private:
    int getTime(string timePoint){
        int hours = (timePoint[0]-'0')*10 + (timePoint[1]-'0');
        int minutes = (timePoint[3]-'0')*10 + (timePoint[4]-'0');
        return hours*60+minutes;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> arr;
        int minDiff = INT_MAX;
        int n = timePoints.size();
        int lastTime = getTime("23:59");
        for(auto &timePoint : timePoints){
            auto t = getTime(timePoint);
            arr.push_back(t);
        }
        sort(begin(arr), end(arr));
        for(int i=0; i<n-1; i++){
            minDiff = min(minDiff, getMinDiff(arr[i], arr[i+1], lastTime));
        }
        minDiff = min(minDiff, getMinDiff(arr[0], arr[n-1], lastTime));
        return minDiff;
    }

    int getMinDiff(int t1, int t2, int lastTime){
        int diff1 = t2 - t1;
        int diff2 = (lastTime - t2) + t1+1;
        return min(diff1, diff2);
    }
};