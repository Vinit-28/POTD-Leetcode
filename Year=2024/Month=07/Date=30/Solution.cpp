// Problem Link : https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/


// Solution //
class Solution {
public:
    int minimumDeletions(string s) {
        int minOps = INT_MAX;
        int n = s.length();
        int prefix[n];
        prefix[0] = s[0]=='b';
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + (s[i]=='b');
        }
        for(int i=0; i<n; i++){
            if( s[i] == 'b' ){
                int ops = prefix[i]-1;
                int aAhead = (n-i-1) - (prefix[n-1]-prefix[i]);
                ops += aAhead;
                minOps = min(minOps, ops);
            }
        }
        // Delete All A's //
        int aCount = n-prefix[n-1];
        minOps = min(minOps, aCount);
        // Delete All B's //
        int bCount = prefix[n-1];
        minOps = min(minOps, bCount);

        return minOps==INT_MAX? 0 : minOps;
    }
};