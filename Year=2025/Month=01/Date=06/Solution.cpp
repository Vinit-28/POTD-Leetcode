// Problem Link : https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/


// Solution //
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        int ones = boxes[0]=='1';
        for(int idx=1; idx<n; idx++){
            ans[idx] = ans[idx-1] + ones;
            ones += boxes[idx]=='1';
        }
        ones = boxes[n-1]=='1';
        int prevCost = 0;
        for(int idx=n-2; idx>=0; idx--){
            int currCost = prevCost + ones;
            ans[idx] += currCost;
            ones += boxes[idx]=='1';
            prevCost = currCost;
        }
        return ans;
    }
};