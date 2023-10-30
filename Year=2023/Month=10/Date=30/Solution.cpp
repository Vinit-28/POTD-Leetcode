// Problem Link : https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/


// Solution //
class Solution {
public:
    static bool comp(int &a, int &b){
        int aCount = __builtin_popcount(a);
        int bCount = __builtin_popcount(b);
        if( aCount == bCount ) return a<b;
        return aCount < bCount;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};