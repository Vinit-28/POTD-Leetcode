// Problem Link : https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/


// Solution //
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        vector<int> res(n);

        for(int idx=0; idx<n; idx++){
            arr.push_back({nums[idx], idx});
        }
        sort(begin(arr), end(arr));
        int start = 0;
        for(int idx=1; idx<n; idx++){
            int diff = arr[idx].first - arr[idx-1].first;
            if( diff > limit ){
                sortTheWindow(arr, res, start, idx-1);
                start = idx;
            }
        }
        sortTheWindow(arr, res, start, n-1);
        return res;
    }
private:
    void sortTheWindow(vector<pair<int,int>> &arr, vector<int> &res, int start, int end){
        vector<int> indices;
        for(int i=start; i<=end; i++){
            int idx = arr[i].second;
            indices.push_back(idx);
        }
        sort(indices.begin(), indices.end());
        for(int i=start; i<=end; i++){
            int val = arr[i].first;
            int idx = indices[i-start];
            res[idx] = val;
        }
    }
};