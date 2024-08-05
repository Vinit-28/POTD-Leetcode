// Problem Link : https://leetcode.com/problems/kth-distinct-string-in-an-array/description/


// Solution //
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int count = 0;
        string ans = "";
        unordered_map<string, int> mpp;
        for(auto &s : arr) mpp[s] += 1;
        for(auto &s : arr){
            count += (mpp[s]==1);
            if( count == k ){
                ans = s;
                break;
            }
        }
        return ans;
    }
};