// Problem Link : https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/description/


// Solution //
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dx = abs(sx - fx);
        int dy = abs(sy - fy);
        if( dx == 0 && dy == 0 && t == 1 ){
            return false;
        }
        int stepsReq = min(dx, dy) + (max(dx, dy) - min(dx, dy));
        return stepsReq <= t;
    }
};