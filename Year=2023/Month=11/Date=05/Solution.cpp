// Problem Link : https://leetcode.com/problems/find-the-winner-of-an-array-game/description/


// Solution //
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 0, j = 1, count = 0;
        while( j<n ){
            if( arr[i] > arr[j] ){
                count += 1;
            } else{
                count = 1;
                i = j;
            }
            j += 1;
            if( count == k ){
                return arr[i];
            }
        }
        return arr[i];
    }
};