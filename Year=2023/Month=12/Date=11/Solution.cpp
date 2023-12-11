// Problem Link : https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/


// Solution //
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int freq = 1, n = arr.size();
        int tarFreq = (n/4);
        for(int i=1;i<n;i++){
            if( arr[i] != arr[i-1] ){
                freq = 1;
            } else{
                freq += 1;
            }
            if( freq > tarFreq ) return arr[i];
        }
        return arr[0];
    }
};