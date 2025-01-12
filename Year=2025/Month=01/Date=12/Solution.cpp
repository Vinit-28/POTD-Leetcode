// Problem Link : https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/


// Solution //
class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> lockedOpen, unlockeds;
        int n = s.size();
        for(int idx=0; idx<n; idx++){
            if( locked[idx] == '0' ){
                unlockeds.push(idx);
            } else{
                if( s[idx] == '(' ){
                    lockedOpen.push(idx);
                } else if( lockedOpen.empty()==false ){
                    lockedOpen.pop();
                } else if( unlockeds.empty()==false ){
                    unlockeds.pop();
                } else{
                    return false;
                }
            }
        }
        while( lockedOpen.empty()==false ){
            int pos = lockedOpen.top(); lockedOpen.pop();
            if( unlockeds.empty() || unlockeds.top() < pos ){
                return false;
            }
            unlockeds.pop();
        }
        return (unlockeds.size()&1)==0;
    }
};