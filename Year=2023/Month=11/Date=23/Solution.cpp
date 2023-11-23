// Problem Link : https://leetcode.com/problems/arithmetic-subarrays/description/


// Solution //
class Solution {
public:

    bool isArithmeticSeq(vector<int> &arr){
        if( arr.size() < 2 ) return false;
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0], n = arr.size();
        for(int i=2;i<n;i++){
            if( diff != (arr[i] - arr[i-1]) ){
                return false;
            }
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> ans;
        for(int i=0;i<m;i++){
            int start = l[i], end = r[i];
            vector<int> arr;
            arr.insert(arr.begin(), nums.begin()+start, nums.begin()+end+1);
            ans.push_back(isArithmeticSeq(arr));
        }
        return ans;
    }
};
