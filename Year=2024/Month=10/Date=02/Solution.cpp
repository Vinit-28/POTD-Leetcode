// Problem Link : https://leetcode.com/problems/rank-transform-of-an-array/description/


// Solution //
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        vector<pair<int,int>> a;
        for(int i=0; i<n; i++){
            a.push_back({arr[i], i});
        }
        sort(begin(a), end(a));
        int rank = 0;
        int prevEle = -1;
        for(auto &[ele, idx] : a){
            if( ele != prevEle ) rank += 1, prevEle = ele;
            ans[idx] = rank;
        }
        return ans;
    }
};