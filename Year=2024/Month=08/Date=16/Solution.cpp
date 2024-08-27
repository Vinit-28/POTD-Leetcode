// Problem Link : https://leetcode.com/problems/maximum-distance-in-arrays/description/



// Solution //
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int min1 = 0, max1 = 0;
        int min2 = -1, max2 = -1;
        for(int idx=1; idx<n; idx++){
            if( arrays[idx][0] <= arrays[min1][0] ){
                min2 = min1, min1 = idx;
            } else if( min2 == -1 || arrays[idx][0] < arrays[min2][0] ){
                min2 = idx;
            }
            if( arrays[idx].back() >= arrays[max1].back() ){
                max2 = max1, max1 = idx;
            } else if( max2 == -1 || arrays[idx].back() > arrays[max2].back() ){
                max2 = idx;
            }
        }
        if( max1 != min1 ) return arrays[max1].back() - arrays[min1][0];
        return max((arrays[max1].back() - arrays[min2][0]), (arrays[max2].back() - arrays[min1][0]));
    }
};