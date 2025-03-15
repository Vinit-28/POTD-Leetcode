// Problem Link : https://leetcode.com/problems/zero-array-transformation-ii/description/


// Solution //
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0, u = queries.size();
        int ans = -1;
        while( l <= u ){
            int mid = (l+u)/2;
            if( isPossible(nums, queries, mid) ){
                u = mid-1;
                ans = mid;
            } else{
                l = mid+1;
            }
        }
        return ans;
    }
private:
    bool isPossible(vector<int> &nums, vector<vector<int>> &queries, int tq){
        int n = nums.size();
        vector<int> ps(n, 0);
        for(int qIdx=0; qIdx<tq; qIdx++){
            int l = queries[qIdx][0], r = queries[qIdx][1], v = queries[qIdx][2];
            ps[l] += v;
            if( r < n-1 ) ps[r+1] -= v;
        }
        for(int idx=0,sum=0; idx<n; idx++){
            sum += ps[idx];
            if( sum < nums[idx] ) return false;
        }
        return true;;
    }
};