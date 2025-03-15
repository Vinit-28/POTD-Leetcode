// Problem Link : https://leetcode.com/problems/alternating-groups-ii/description/


// Solution //
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0;
        int n = colors.size();
        int count = 1;
        int start = 0;
        int initialCount = count;
        for(int i=1; i<n; i++){
            if( colors[i] == colors[i-1] ){
                ans += max(0, count-k+1);
                count = 1;
                start = i;
            } else{
                count += 1;
            }
            initialCount = start==0? count : initialCount;
        }
        if( colors[n-1] == colors[0] ){
            ans += max(0, count-k+1);
        } else{
            ans += max(0, min((count+initialCount)-k+1, count));
        }
        return ans;
    }
};