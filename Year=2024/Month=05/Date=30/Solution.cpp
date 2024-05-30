// Problem Link : https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/


// Solution //
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int pairs = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            int val = 0;
            for(int j=i; j<n; j++){
                val ^= arr[j];
                if( val == 0 ){
                    pairs += (j-i);
                }
            }
        }
        return pairs;
    }
};