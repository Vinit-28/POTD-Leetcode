// Problem Link : https://leetcode.com/problems/my-calendar-ii/description/


// Solution //
class MyCalendarTwo {
private:
    map<int, int> intervals;
public:
    MyCalendarTwo() {
        intervals = map<int, int>();
    }
    
    bool book(int start, int end) {
        intervals[start] += 1;
        intervals[end] -= 1;
        int count = 0;
        for(auto &p : intervals){
            count += p.second;
            if( count > 2 ) break;
        }
        if( count > 2 ){
            intervals[start] -= 1;
            intervals[end] += 1;
            return false;
        }
        return true;
    }
};