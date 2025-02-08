// Problem Link : https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/


// Solution //
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, int> mpp, ballClr;
        vector<int> ans;
        mpp[0] = 0;
        for(auto &q: queries){
            int ball = q[0];
            int currClr = ballClr[ball];
            int newClr = q[1];
            if( --mpp[currClr] <= 0 && currClr != 0 ){
                mpp.erase(currClr);
            }
            mpp[newClr] += 1;
            ballClr[ball] = newClr;
            ans.push_back(mpp.size()-1);
        }
        return ans;
    }
};