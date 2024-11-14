// Problem Link : https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/


// Solution //
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, u = 1e5;
        int ans = -1;
        while( l<=u ){
            int mid = (l+u)/2;
            if( isValid(n, quantities, mid) ){
                ans = mid;
                u = mid-1;
            } else{
                l = mid+1;
            }
        }
        return ans;
    }
    
    bool isValid(int n, vector<int> &nums, int mid){
        for(auto &ele : nums){
            int d = ceil(ele*1.0/mid);
            n -= d;
            if( n < 0 ) return false;
        }
        return true;
    }
};