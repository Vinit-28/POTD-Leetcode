// Problem Link : https://leetcode.com/problems/unique-number-of-occurrences/description/


// Solution //
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> freq;
        set<int> uniFreq;
        for(auto &ele : arr){
            freq[ele] += 1;
        }
        for(auto &p : freq){
            if( uniFreq.find(p.second) != uniFreq.end() ){
                return false;
            }
            uniFreq.insert(p.second);
        }
        return true;
    }
};