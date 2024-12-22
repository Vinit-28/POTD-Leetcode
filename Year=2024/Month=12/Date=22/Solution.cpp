// Problem Link : https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/description/


// Solution //
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int totalQ = queries.size();
        vector<int> ans(totalQ);
        vector<int> st; // Intentionally made stack using vector to do Binary Search //
        // Swapping every query having a > b //
        for(int i=0; i<totalQ; i++){
            queries[i].push_back(i);
            if( queries[i][0] > queries[i][1] ) swap(queries[i][0], queries[i][1]);
        }
        // Sort queries on the basis of b, in descending order //
        sort(begin(queries), end(queries), [](vector<int> &q1, vector<int> &q2)->bool{
            return q1[1] > q2[1];
        });
        int hIdx = heights.size()-1;
        // Finding the answer for every query //
        for(auto &q : queries){
            int alice = q[0], bob = q[1], qIdx = q[2];
            // Maintain the monotonic stack till index j //
            while( hIdx > bob ){
                // Monotonic Stack //
                while( st.empty()==false && heights[st.back()] <= heights[hIdx] ){
                    st.pop_back();
                }
                st.push_back(hIdx);
                hIdx -= 1;
            }
            // heights[alice] < heights[bob], then alice will move to heights[bob] //
            if( alice == bob || heights[alice] < heights[bob] ){
                ans[qIdx] = bob;
            } else{
                // Do a binary search on monotonic stack to find the rightmost element
                // having height greater than > heights[alice].
                int meetStackIdx = _search(st, heights, heights[alice]);
                ans[qIdx] = meetStackIdx==-1? -1 : st[meetStackIdx];
            }
        }
        return ans;
    }
    
    
    int _search(vector<int> &st, vector<int> &heights, int val){
        int l = 0, u = st.size()-1;
        int idx = -1;
        while( l <= u ){
            int mid = (l+u)/2;
            if( heights[st[mid]] > val ){
                idx = mid;
                l = mid+1;
            } else{
                u = mid-1;
            }
        }
        return idx;
    }
};