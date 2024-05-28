// Problem Link : https://leetcode.com/problems/get-equal-substrings-within-budget/description/


// Solution //
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxLen = 0;
        int right = 0;
        int n = s.length();
        int cost = 0;
        for(int left=0; left<n; left++){
            // Extend the window //
            while( right<n && (cost+getCost(s[right], t[right])) <= maxCost ){
                cost += getCost(s[right], t[right]);
                right += 1;
            }
            maxLen = max(maxLen, (right-left));
            cost -= getCost(s[left], t[left]);
        }
        return maxLen;
    }

    int getCost(char &from, char &to){
        return abs(int(from-to));
    }
};