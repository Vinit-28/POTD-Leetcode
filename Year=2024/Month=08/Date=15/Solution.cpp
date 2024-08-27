// Problem Link : https://leetcode.com/problems/lemonade-change/description/



// Solution //
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(auto &bill : bills){
            (bill==5? five++ : bill==10? ten++ : 0);
            int change = bill - 5;
            if( change > 0 ){
                int tenReq = min(change/10, ten);
                ten -= tenReq;
                change -= (tenReq*10);
                if( (change/5) > five ) return false;
                five -= (change/5);
            }
        }
        return true;
    }
};