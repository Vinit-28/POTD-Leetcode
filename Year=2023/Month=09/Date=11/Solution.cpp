// Problem Link : https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/


// Solution //
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> hmap;
        vector<vector<int>> ans;
        int n = groupSizes.size();
        for(int i=0;i<n;i++){
            auto &group = hmap[groupSizes[i]];
            if( group.size() == groupSizes[i] ){
                ans.push_back(group);
                group = {i};
            } else{
                group.push_back(i);
            }
        }
        for(auto &p : hmap){
            ans.push_back(p.second);
        }
        return ans;
    }
};