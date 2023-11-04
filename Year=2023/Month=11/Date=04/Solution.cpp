// Problem Link : https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/


// Solution //
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int leftTime = 0, rightTime = 0;
        if( !left.empty() ){
            leftTime = *max_element(left.begin(), left.end());
        }
        if( !right.empty() ){
            rightTime = (n - (*min_element(right.begin(), right.end())));
        }
        return max(leftTime, rightTime);
    }
};