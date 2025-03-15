// Problem Link : https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/


// Solution //
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        vector<int> ps(n, 0);
        int mini = k;
        ps[0] = blocks[0]=='W';
        for(int i=1; i<n; i++){
            ps[i] = blocks[i]=='W';
            ps[i] += ps[i-1];
        }
        for(int i=0; i<=n-k; i++){
            int white = i==0? ps[i+k-1] : ps[i+k-1]-ps[i-1];
            mini = min(mini, white);
        }
        return mini;
    }
};