// Problem Link : https://leetcode.com/problems/sort-the-people/description/


// Solution //
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> mpp;
        int n = names.size();
        for(int idx=0; idx<n; idx++){
            mpp[heights[idx]] = names[idx];
        }
        int idx = 0;
        for(auto [height, name] : mpp){
            names[idx] = name;
            idx += 1;
        }
        reverse(begin(names), end(names));
        return names;
    }
};