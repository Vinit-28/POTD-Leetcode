// Problem Link : https://leetcode.com/problems/path-crossing/description/


// Solution //
class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        set<pair<int,int>> s;
        s.insert({x, y});
        for(auto &ch : path){
            if( ch == 'N' ) y += 1;
            else if( ch == 'S' ) y -= 1;
            else if( ch == 'W' ) x -= 1;
            else x += 1;
            if( s.find({x, y}) != s.end() ) return true;
            s.insert({x, y});
        }
        return false;
    }
};