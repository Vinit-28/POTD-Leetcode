// Problem Link : https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/


// Solution //
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> losses;
        vector<int> a, b;
        for(auto &match : matches){
            int w = match[0], l = match[1];
            losses[l] += 1;
            losses[w];
        }
        for(auto &p : losses){
            if( p.second == 0 ){
                a.push_back(p.first);
            } else if( p.second == 1 ){
                b.push_back(p.first);
            }
        }
        return {a,b};
    }
};
