// Problem Link : https://leetcode.com/problems/group-anagrams/description/


// Solution //
class Solution {
public:
    string getSortedString(string str){
        sort(str.begin(), str.end());
        return str;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> arrMap;
        for(auto &str : strs){
            string sortedStr = getSortedString(str);
            arrMap[sortedStr].push_back(str);
        }
        for(auto &p : arrMap){
            ans.push_back(p.second);
        }
        return ans;
    }
};