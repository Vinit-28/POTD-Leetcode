// Problem Link : https://leetcode.com/problems/destination-city/description/


// Solution //
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, bool> hmap;
        for(auto &path : paths){
            hmap[path[0]] = true;
        }
        for(auto &path : paths){
            if( hmap.find(path[1]) == hmap.end() ){
                return path[1];
            }
        }
        return "";
    }
};