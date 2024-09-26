// Problem Link : https://leetcode.com/problems/my-calendar-i/description/


// Solution //
class MyCalendar {
private:
    map<int, int> intervals;
public:
    MyCalendar() {
        intervals = map<int,int>();
    }
    
    bool book(int start, int end) {
        auto iter = intervals.lower_bound(start);
        if( iter != intervals.begin() ) iter--;
        int count = 0;
        while( iter != intervals.end() && iter->first < end ){
            if( iter->first <= start && iter->second > start ) count += 1;
            else if( iter->first <= end && iter->second > end ) count += 1;
            else if( start <= iter->first && end > iter->first ) count += 1;
            iter++;
        }
        // Can be added //
        if( count == 0 ){
            intervals[start] = end;
            return true;
        }
        return false;
    }
};