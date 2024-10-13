// Problem Link : https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/


// Solution //
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> a, d;
        for(auto in : intervals){
            a.push_back(in[0]);
            d.push_back(in[1]);
        }
        sort(begin(a), end(a));
        sort(begin(d), end(d));
        int ans = 1;
        int count = 0;
        int aIdx = 0, dIdx = 0;
        int n = a.size();
        while(aIdx<n){
            if(a[aIdx] <= d[dIdx]){
                count += 1;
                aIdx += 1;
            } else{
                count -= 1;
                dIdx += 1;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};