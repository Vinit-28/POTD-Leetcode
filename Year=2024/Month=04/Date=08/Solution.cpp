// Problem Link : https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/


// Solution //
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int idx = 0;
        int one = 0, zero = 0;
        for(int sp: students){
            if( sp == 0 ) zero += 1;
            else one += 1;
            q.push(sp);
        }
        while( q.empty()==false && idx < sandwiches.size() ){
            if( q.front() == sandwiches[idx] ){
                if( q.front() == 0 ) zero -= 1;
                else one -= 1;
                q.pop();
                idx += 1;
            } else{
                auto s = sandwiches[idx];
                if( (s==0 && zero <= 0) || (s==1 && one <= 0) ) break;
                auto sp = q.front();
                q.pop();
                q.push(sp);
            }
        }
        return q.size();
    }
};